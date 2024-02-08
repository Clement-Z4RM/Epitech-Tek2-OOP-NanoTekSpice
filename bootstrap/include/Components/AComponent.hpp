/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** AComponent.hpp
*/

#ifndef BOOTSTRAP_ACOMPONENT_HPP_
#define BOOTSTRAP_ACOMPONENT_HPP_

#include <map>
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
    public:
        void simulate(std::size_t tick) override;
        void insert(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        [[nodiscard]] Tristate getLink(std::size_t pin) const;
        [[nodiscard]] const Tristate at(std::size_t pin) const override;
    };
}

#endif /* !BOOTSTRAP_ACOMPONENT_HPP_ */
