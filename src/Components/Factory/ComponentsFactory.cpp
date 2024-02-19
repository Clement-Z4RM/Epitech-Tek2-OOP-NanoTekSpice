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
        explicit SampleComponent(Component type) : _type(type) {};

        [[nodiscard]] Component getType() const override {
            return _type;
        }

        void simulate([[maybe_unused]] std::size_t tick) override {
            std::cout << _type << std::endl;
        }

        [[nodiscard]] Tristate compute([[maybe_unused]] std::size_t pin) override {
            return Tristate::Undefined;
        }

        void setLink([[maybe_unused]] std::size_t pin, [[maybe_unused]] std::unique_ptr<IComponent> &other,
                     [[maybe_unused]] std::size_t otherPin) override {}

    private:
        Component _type;
    };
}

const std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>>

        nts::ComponentsFactory::_components = {
        // Special components
        {"input",  []() { return std::make_unique<SampleComponent>(_input); }},
        {"output", []() { return std::make_unique<SampleComponent>(_output); }},
        {"true",   []() { return std::make_unique<SampleComponent>(_true); }},
        {"false",  []() { return std::make_unique<SampleComponent>(_false); }},
        {"clock",  []() { return std::make_unique<SampleComponent>(_clock); }},

        // Elementary components
        {"and",    []() { return std::make_unique<SampleComponent>(_and); }},
        {"or",     []() { return std::make_unique<SampleComponent>(_or); }},
        {"xor",    []() { return std::make_unique<SampleComponent>(_xor); }},
        {"not",    []() { return std::make_unique<SampleComponent>(_not); }},

        // Gates components
        {"4001",   []() { return std::make_unique<SampleComponent>(_4001); }},
        {"4011",   []() { return std::make_unique<SampleComponent>(_4011); }},
        {"4030",   []() { return std::make_unique<SampleComponent>(_4030); }},
        {"4069",   []() { return std::make_unique<SampleComponent>(_4069); }},
        {"4071",   []() { return std::make_unique<SampleComponent>(_4071); }},
        {"4081",   []() { return std::make_unique<SampleComponent>(_4081); }},

        // Advanced components
        {"4008",   []() { return std::make_unique<SampleComponent>(_4008); }},
        {"4013",   []() { return std::make_unique<SampleComponent>(_4013); }},
        {"4017",   []() { return std::make_unique<SampleComponent>(_4017); }},
        {"4040",   []() { return std::make_unique<SampleComponent>(_4040); }},
        {"4094",   []() { return std::make_unique<SampleComponent>(_4094); }},
        {"4512",   []() { return std::make_unique<SampleComponent>(_4512); }},
        {"4514",   []() { return std::make_unique<SampleComponent>(_4514); }},
        {"4801",   []() { return std::make_unique<SampleComponent>(_4801); }},
        {"2716",   []() { return std::make_unique<SampleComponent>(_2716); }},

        // Logger
        {"logger", []() { return std::make_unique<SampleComponent>(_logger); }}
};

std::unique_ptr<nts::IComponent> nts::ComponentsFactory::createComponent(const std::string &type) {
    if (_components.contains(type))
        return _components.at(type)();
    return nullptr;
}

bool nts::ComponentsFactory::isComponentExists(const std::string &type) {
    return _components.contains(type);
}
