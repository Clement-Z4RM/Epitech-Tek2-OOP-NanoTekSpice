/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFalse.hpp
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class ComponentFalse : public AComponent {
    public:
        ComponentFalse();

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
