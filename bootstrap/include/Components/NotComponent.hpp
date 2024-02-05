/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** NotComponent.hpp
*/

#ifndef BOOTSTRAP_NOTCOMPONENT_HPP_
#define BOOTSTRAP_NOTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
    public:
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !BOOTSTRAP_NOTCOMPONENT_HPP_ */
