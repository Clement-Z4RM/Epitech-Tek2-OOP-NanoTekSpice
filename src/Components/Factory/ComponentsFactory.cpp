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
#include "ComponentsFactory.hpp"

#include <iostream>

// TODO: Use real components and replace std::unique_ptr<SampleComponent> with std::unique_ptr<COMPONENT>
namespace nts {
    class SampleComponent : public AComponent {
    public:
        explicit SampleComponent(Component type) : AComponent(type, 13) {
            _excludedPins.push_back(7);
        }

        [[nodiscard]] Component getType() const override {
            return _type;
        }

        void simulate([[maybe_unused]] std::size_t tick) override {
            std::cout << _type << std::endl;
        }

        [[nodiscard]] Tristate compute([[maybe_unused]] std::size_t pin) override {
            return Tristate::Undefined;
        }

        [[nodiscard]] Tristate at([[maybe_unused]] std::size_t pin) const override {
            return _state;
        }

    };
}

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

bool nts::ComponentsFactory::isValidComponentType(const std::string &type) {
    return _components.contains(type);
}
