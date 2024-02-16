/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentsFactory.cpp
*/

#include "ComponentsFactory.hpp"

#include <utility>
#include <iostream>

// TODO: Use real components and replace std::unique_ptr<SampleComponent> with std::unique_ptr<COMPONENT>
namespace nts {
    class SampleComponent : public IComponent {
    public:
        explicit SampleComponent(std::string name) : _name(std::move(name)) {};

        void simulate([[maybe_unused]] std::size_t tick) override {
            std::cout << _name << std::endl;
        }

        Tristate compute([[maybe_unused]] std::size_t pin) override {
            return Tristate::Undefined;
        }

        void setLink([[maybe_unused]] std::size_t pin, [[maybe_unused]] IComponent &other,
                     [[maybe_unused]] std::size_t otherPin) override {}

    private:
        std::string _name;
    };
}

const std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>>

        nts::ComponentsFactory::_components = {
        // Special components
        {"input",  []() { return std::make_unique<SampleComponent>("input"); }},
        {"output", []() { return std::make_unique<SampleComponent>("output"); }},
        {"true",   []() { return std::make_unique<SampleComponent>("true"); }},
        {"false",  []() { return std::make_unique<SampleComponent>("false"); }},
        {"clock",  []() { return std::make_unique<SampleComponent>("clock"); }},

        // Elementary components
        {"and",    []() { return std::make_unique<SampleComponent>("and"); }},
        {"or",     []() { return std::make_unique<SampleComponent>("or"); }},
        {"xor",    []() { return std::make_unique<SampleComponent>("xor"); }},
        {"not",    []() { return std::make_unique<SampleComponent>("not"); }},

        // Gates components
        {"4001",   []() { return std::make_unique<SampleComponent>("4001"); }},
        {"4011",   []() { return std::make_unique<SampleComponent>("4011"); }},
        {"4030",   []() { return std::make_unique<SampleComponent>("4030"); }},
        {"4069",   []() { return std::make_unique<SampleComponent>("4069"); }},
        {"4071",   []() { return std::make_unique<SampleComponent>("4071"); }},
        {"4081",   []() { return std::make_unique<SampleComponent>("4081"); }},

        // Advanced components
        {"4008",   []() { return std::make_unique<SampleComponent>("4008"); }},
        {"4013",   []() { return std::make_unique<SampleComponent>("4013"); }},
        {"4017",   []() { return std::make_unique<SampleComponent>("4017"); }},
        {"4040",   []() { return std::make_unique<SampleComponent>("4040"); }},
        {"4094",   []() { return std::make_unique<SampleComponent>("4094"); }},
        {"4512",   []() { return std::make_unique<SampleComponent>("4512"); }},
        {"4514",   []() { return std::make_unique<SampleComponent>("4514"); }},
        {"4801",   []() { return std::make_unique<SampleComponent>("4801"); }},
        {"2716",   []() { return std::make_unique<SampleComponent>("2716"); }},

        // Logger
        {"logger", []() { return std::make_unique<SampleComponent>("logger"); }}
};

std::unique_ptr<nts::IComponent> nts::ComponentsFactory::createComponent(const std::string &type) {
    if (_components.contains(type))
        return _components.at(type)();
    return nullptr;
}

bool nts::ComponentsFactory::isComponentExists(const std::string &type) {
    return _components.contains(type);
}
