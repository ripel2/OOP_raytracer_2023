/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SfmlRenderer
*/

#include "SfmlRenderer.hpp"

RayTracer::SfmlRenderer::SfmlRenderer(size_t width, size_t height)
{
    this->_window.create(sf::VideoMode(width, height), "Raytracer", sf::Style::Close | sf::Style::Titlebar);
    this->_image.create(width, height, sf::Color::Black);
    this->_texture.loadFromImage(_image);
    this->_sprite.setTexture(_texture);
}

RayTracer::SfmlRenderer::~SfmlRenderer()
{
    this->_window.~RenderWindow();
}

static bool isFileExisting(const std::string &filename)
{
    struct stat buffer;

    if (stat(filename.c_str(), &buffer) == 0) {
        return true;
    } else {
        return false;
    }
}

static std::string getDateTime()
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::string dateTime = std::to_string(tm.tm_mday) + ":" + std::to_string(tm.tm_mon + 1) + ":" + std::to_string(tm.tm_year + 1900) + "-" + std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min) + ":" + std::to_string(tm.tm_sec);

    return dateTime;
}

void RayTracer::SfmlRenderer::execScreenshot()
{
    std::string dirName = "screenshots";
    std::size_t screenshotNb = 1;

    if (!isFileExisting(dirName)) {
        mkdir(dirName.c_str(), 0777);
    }
    _image.saveToFile(dirName + "/screenshot_" + getDateTime() + ".png");
}

void RayTracer::SfmlRenderer::event()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            }
            if (event.key.code == sf::Keyboard::P) {
                _zoom++;
            }
            if (event.key.code == sf::Keyboard::L) {
                _zoom--;
            }
            if (event.key.code == sf::Keyboard::S) {
                execScreenshot();
            }
        }
    }
}

void RayTracer::SfmlRenderer::renderImage()
{
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    _window.clear();
    _window.draw(_sprite);
    _window.display();
}

void *RayTracer::SfmlRenderer::execRenderThread(std::size_t width, std::size_t height, const Scene &scene, std::size_t start, std::size_t end)
{
    for (std::size_t i = start; i < end; i++) {
        for (std::size_t j = 0 ; j < width; j++) {
            Color color = getColor(static_cast<double>(j) / static_cast<double>(width), 1.0 - (static_cast<double>(i) / static_cast<double>(height)), scene);
            _mutex.lock();
            _image.setPixel(j, i, sf::Color(static_cast<int>(color[0] * 255), static_cast<int>(color[1] * 255), static_cast<int>(color[2] * 255)));
            event();
            if (!_window.isOpen()) {
                _mutex.unlock();
                return nullptr;
            }
            _mutex.unlock();
        }
        _mutex.lock();
        renderImage();
        _mutex.unlock();
    }
    return nullptr;
}

void RayTracer::SfmlRenderer::loadImage(std::size_t width, std::size_t height, const Scene &scene)
{
    std::vector<std::thread> threads;
    std::size_t thread_nb = 1;
    std::size_t linesPerThread;

    for (std::size_t i = 1; i <= std::thread::hardware_concurrency(); i++) {
        if (height % i == 0) {
            thread_nb = i;
        }
    }
    linesPerThread = height / thread_nb;
    for (std::size_t i = 0; i < thread_nb; i++) {
        threads.emplace_back(&RayTracer::SfmlRenderer::execRenderThread, this, width, height, std::ref(scene), i * linesPerThread, (i + 1) * linesPerThread);
    }
    for (auto &thread : threads) {
        thread.join();
    }
}

void RayTracer::SfmlRenderer::render(std::size_t width, std::size_t height, const Scene &scene)
{
    loadImage(width, height, scene);
    while (_window.isOpen()) {
        event();
        renderImage();
    }
}
