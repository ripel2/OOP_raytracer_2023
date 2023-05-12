/*
** EPITECH PROJECT, 2023
** OOP_raytracer_2023 [WSL: Ubuntu]
** File description:
** Main
*/

#include "PluginLoader.hpp"

#include "Parser.hpp"

static void print_help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

static int start_raytracer(char **av)
{
    RayTracer::PluginLoader loader;
    RayTracer::Parser parser(&loader);

    try {
        loader.LoadPlugins("./plugins");
    } catch (const RayTracer::PluginLoaderError &e) {
        std::cerr << av[0] << ": " << "plugin loader error: " << e.what() << std::endl;
        return 84;
    } catch (const RayTracer::FactoryError &e) {
        std::cerr << av[0] << ": " << "factory error: " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << av[0] << ": " << "unknown error: " << e.what() << std::endl;
        return 84;
    }

    try {
        parser.parse(av[1]);
    } catch (const RayTracer::ParserError &e) {
        std::cerr << av[0] << ": " << "parser error: " << e.what() << std::endl;
        return 84;
    } catch (const RayTracer::BuilderError &e) {
        std::cerr << av[0] << ": " << "builder error: " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << av[0] << ": " << "unknown error: " << e.what() << std::endl;
        return 84;
    }

    std::unique_ptr<RayTracer::Scene> scene = std::move(parser.getScene());
    std::unique_ptr<RayTracer::IRenderer> renderer = std::move(parser.getRenderer());

    try {
        renderer->render(parser.getImageWidth(), parser.getImageHeight(), *scene, parser.getSamplesPerPixel());
    } catch (const std::exception &e) {
        std::cerr << av[0] << ": " << "unknown error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        print_help();
        return 84;
    }
    return start_raytracer(av);
}
