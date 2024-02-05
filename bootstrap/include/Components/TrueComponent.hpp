/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** TrueComponent.hpp
*/

#ifndef BOOTSTRAP_TRUECOMPONENT_HPP_
#define BOOTSTRAP_TRUECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !BOOTSTRAP_TRUECOMPONENT_HPP_ */
