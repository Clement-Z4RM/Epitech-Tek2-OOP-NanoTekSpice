/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentNot.hpp
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "../../AComponent.hpp"

namespace nts {
    class ComponentNot : public AComponent {
    public:
        ComponentNot();

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !NOTCOMPONENT_HPP_ */