/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AndComponent.hpp
*/

#ifndef BOOTSTRAP_ANDCOMPONENT_HPP_
#define BOOTSTRAP_ANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !BOOTSTRAP_ANDCOMPONENT_HPP_ */
