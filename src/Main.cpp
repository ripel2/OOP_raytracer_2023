/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Main
*/

#include "PluginLoader.hpp"

#include "Parser.hpp"

int main(int ac, char **av)
{
    RayTracer::PluginLoader loader;
    RayTracer::Parser parser(&loader);

    loader.LoadPlugins("./plugins");

    // add error handling
    try {
        parser.parse(av[1]);
    } catch (const RayTracer::ParserError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    std::unique_ptr<RayTracer::Scene> scene = std::move(parser.getScene());
    std::unique_ptr<RayTracer::IRenderer> renderer = std::move(parser.getRenderer());

    renderer->render(parser.getImageWidth(), parser.getImageHeight(), *scene);
    return 0;
}
