/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentsFactory.cpp
*/

#include "../AComponent.hpp"
#include "../Special/Input/ComponentInput.hpp"
#include "../Special/Output/ComponentOutput.hpp"
#include "../Special/True/ComponentTrue.hpp"
#include "../Special/False/ComponentFalse.hpp"
#include "../Special/Clock/ComponentClock.hpp"
#include "../Elementary/And/ComponentAnd.hpp"
#include "../Elementary/Or/ComponentOr.hpp"
#include "../Elementary/Xor/ComponentXor.hpp"
#include "../Elementary/Not/ComponentNot.hpp"
#include "../Gates/4001/Component4001.hpp"
#include "../Gates/4011/Component4011.hpp"
#include "../Gates/4030/Component4030.hpp"
#include "../Gates/4069/Component4069.hpp"
#include "../Gates/4071/Component4071.hpp"
#include "../Gates/4081/Component4081.hpp"
#include "../Advanced/4008/Component4008.hpp"
#include "../Advanced/4013/Component4013.hpp"
#include "../Advanced/4017/Component4017.hpp"
#include "../Advanced/4040/Component4040.hpp"
#include "../Advanced/4094/Component4094.hpp"
#include "../Advanced/4512/Component4512.hpp"
#include "../Advanced/4514/Component4514.hpp"
#include "../Advanced/4801/Component4801.hpp"
#include "../Advanced/2716/Component2716.hpp"
#include "../Logger/ComponentLogger.hpp"
#include "ComponentsFactory.hpp"

#include <iostream>

const std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> nts::ComponentsFactory::_components = {
        // Special components
        {"input",  []() { return std::make_unique<ComponentInput>(); }},
        {"output", []() { return std::make_unique<ComponentOutput>(); }},
        {"true",   []() { return std::make_unique<ComponentTrue>(); }},
        {"false",  []() { return std::make_unique<ComponentFalse>(); }},
        {"clock",  []() { return std::make_unique<ComponentClock>(); }},

        // Elementary components
        {"and",    []() { return std::make_unique<ComponentAnd>(); }},
        {"or",     []() { return std::make_unique<ComponentOr>(); }},
        {"xor",    []() { return std::make_unique<ComponentXor>(); }},
        {"not",    []() { return std::make_unique<ComponentNot>(); }},

        // Gates components
        {"4001",   []() { return std::make_unique<Component4001>(); }},
        {"4011",   []() { return std::make_unique<Component4011>(); }},
        {"4030",   []() { return std::make_unique<Component4030>(); }},
        {"4069",   []() { return std::make_unique<Component4069>(); }},
        {"4071",   []() { return std::make_unique<Component4071>(); }},
        {"4081",   []() { return std::make_unique<Component4081>(); }},

        // Advanced components
        {"4008",   []() { return std::make_unique<Component4008>(); }},
        {"4013",   []() { return std::make_unique<Component4013>(); }},
        {"4017",   []() { return std::make_unique<Component4017>(); }},
        {"4040",   []() { return std::make_unique<Component4040>(); }},
        {"4094",   []() { return std::make_unique<Component4094>(); }},
        {"4512",   []() { return std::make_unique<Component4512>(); }},
        {"4514",   []() { return std::make_unique<Component4514>(); }},
        {"4801",   []() { return std::make_unique<Component4801>(); }},
        {"2716",   []() { return std::make_unique<Component2716>(); }},

        // Logger
        {"logger", []() { return std::make_unique<ComponentLogger>(); }}
};

std::unique_ptr<nts::IComponent> nts::ComponentsFactory::createComponent(const std::string &type) {
    if (_components.contains(type))
        return _components.at(type)();
    return nullptr;
}

bool nts::ComponentsFactory::isValidComponentType(const std::string &type) {
    return _components.contains(type);
}
