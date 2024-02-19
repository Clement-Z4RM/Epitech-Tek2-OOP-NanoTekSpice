/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentsFactory.hpp
*/

#ifndef NANOTEKSPICE_COMPONENTSFACTORY_HPP_
#define NANOTEKSPICE_COMPONENTSFACTORY_HPP_

#include <functional>
#include <memory>
#include <unordered_map>
#include "IComponent.hpp"

namespace nts {
    class ComponentsFactory {
    public:
        [[nodiscard]] static std::unique_ptr<IComponent> createComponent(const std::string &type);

        [[nodiscard]] static bool isComponentExists(const std::string &type);

    private:
        static const std::unordered_map<std::string, std::function<std::unique_ptr<IComponent>()>> _components;
    };
}

#endif /* !NANOTEKSPICE_COMPONENTSFACTORY_HPP_ */
