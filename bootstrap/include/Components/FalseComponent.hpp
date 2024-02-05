/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** FalseComponent.hpp
*/

#ifndef BOOTSTRAP_FALSECOMPONENT_HPP_
#define BOOTSTRAP_FALSECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !BOOTSTRAP_FALSECOMPONENT_HPP_ */
