/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <map>
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
    public:
        class Error : public std::exception {
        public:
            enum ErrorType {
                PinOutOfRange,
                PinExcluded,
                PinAlreadyLinked
            };

            static const std::string ERRORS[];

            explicit Error(std::string message);

            [[nodiscard]] const char *what() const noexcept override;

        private:
            const std::string _message;
        };

        void simulate(std::size_t tick) override;
        void insert(std::size_t pin, std::unique_ptr<IComponent> &other, std::size_t otherPin) override;
        void setLink(std::size_t pin, std::unique_ptr<IComponent> &other, std::size_t otherPin) override;
        [[nodiscard]] Tristate getLink(std::size_t pin) const;
        [[nodiscard]] Tristate at(std::size_t pin) const override;
    };
}

#endif /* !ACOMPONENT_HPP_ */
