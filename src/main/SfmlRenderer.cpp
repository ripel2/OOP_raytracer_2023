/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SfmlRenderer
*/

#include "SfmlRenderer.hpp"

RayTracer::SfmlRenderer::SfmlRenderer(size_t width, size_t height, RayTracer::Parser &parser)
    : _parser(parser)
{
    this->_window.create(sf::VideoMode(width, height), "Raytracer", sf::Style::Close | sf::Style::Titlebar);
    this->_image.create(width, height, sf::Color::Black);
    this->_texture.loadFromImage(_image);
    this->_sprite.setTexture(_texture);
    this->_view = this->_window.getDefaultView();
    this->_isOpen = true;
    this->_window.setView(_view);
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
            _isOpen = false;
        }
        if (event.type == sf::Event::MouseWheelMoved) {
            if (event.mouseWheel.delta > 0) {
                _view.zoom(0.5);
                _window.setView(_view);
            } else {
                _view.zoom(1.5);
                _window.setView(_view);
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _isOpen = false;
            }
            if (event.key.code == sf::Keyboard::P) {
                _view.zoom(0.5);
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::L) {
                _view.zoom(1.5);
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::S) {
                execScreenshot();
            }
            if (event.key.code == sf::Keyboard::R) {
                _view = _window.getDefaultView();
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::Up) {
                _view.move(0, -10);
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::Down) {
                _view.move(0, 10);
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::Left) {
                _view.move(-10, 0);
                _window.setView(_view);
            }
            if (event.key.code == sf::Keyboard::Right) {
                _view.move(10, 0);
                _window.setView(_view);
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

void *RayTracer::SfmlRenderer::execRenderThread(std::size_t width, std::size_t height, const Scene &scene, std::size_t start, std::size_t end, std::size_t samplesPerPixel, std::size_t depth)
{
    for (std::size_t i = start; i < end; i++) {
        for (std::size_t j = 0 ; j < width; j++) {
            Color color;
            for (std::size_t k = 0; k < samplesPerPixel; k++) {
                for (std::size_t l = 0; l < samplesPerPixel; l++) {
                    double u = (j + (k / static_cast<double>(samplesPerPixel))) / width;
                    double v = 1.0 - (i + (l / static_cast<double>(samplesPerPixel))) / height;
                    color += getColor(u, v, scene, depth);
                }
            }
            color /= samplesPerPixel * samplesPerPixel;
            _mutex.lock();
            event();
            if (!_isOpen) {
                _mutex.unlock();
                return nullptr;
            }
            _image.setPixel(j, i, sf::Color(static_cast<int>(color[0] * 255), static_cast<int>(color[1] * 255), static_cast<int>(color[2] * 255)));
            _mutex.unlock();
        }
        _mutex.lock();
        renderImage();
        _mutex.unlock();
    }
    return nullptr;
}

void RayTracer::SfmlRenderer::loadImage(std::size_t width, std::size_t height, const Scene &scene, std::size_t samplesPerPixel, std::size_t depth)
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
        threads.emplace_back(&RayTracer::SfmlRenderer::execRenderThread, this, width, height, std::ref(scene), i * linesPerThread, (i + 1) * linesPerThread, samplesPerPixel, depth);
    }
    for (auto &thread : threads) {
        thread.join();
    }
}

void RayTracer::SfmlRenderer::render(std::size_t width, std::size_t height, const Scene &scene, std::size_t samplesPerPixel, std::size_t depth)
{
    loadImage(width, height, scene, samplesPerPixel, depth);
    while (_isOpen != false) {
        event();
        renderImage();
    }
}
