/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

void nts::AComponent::simulate(std::size_t tick) {}

/**
 * @brief Link a pin of the current component to another component.
 *
 * @warning PREFER ONLY INTERNAL USE<br><br>
 * If a component is already linked to this pin, it will have a link that does not exist in the opposite direction.<br>
 * Example:<br>
 * AComponent a;<br>
 * AComponent b;<br>
 * AComponent c;<br>
 * c.setLink(1, b, 1);<br>
 * c.setLink(1, a, 1);<br>
 * // b will have a link to a, but a will not have a link to b.
 *
 * @param pin The pin of the current component.
 * @param other The other component.
 * @param otherPin The pin of the other component.
 */
void nts::AComponent::insert(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    _links.insert(std::make_pair(pin, (Link){other, otherPin, other.compute(otherPin)}));
}

/**
 * @brief Link a pin of the current component to another component.<br>
 * It also links the other component to the current component.
 *
 * If the pin is already linked, the link is removed from the other component.
 *
 * @param pin The pin of the current component.
 * @param other The other component.
 * @param otherPin The pin of the other component.
 */
void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    // TODO handle multiple connections on otherPin
    if (_links.find(pin) != _links.end()) {
//        Link link = _links.at(pin);
//
//        link.other.erase(link.otherPin);
        // TODO: exit with error (multiple connections on same pin)
    }
    insert(pin, other, otherPin);
    other.insert(otherPin, *this, pin);
}

/**
 * @brief Get the link of a pin and compute the linked component.
 *
 * @param pin The pin of the current component.
 *
 * @return The computed value of the linked component.
 */
nts::Tristate nts::AComponent::getLink(std::size_t pin) const {
    if (_links.find(pin) == _links.end())
        return Undefined;

    Link link = _links.at(pin);

    return link.other.compute(link.otherPin);
}

const nts::Tristate nts::AComponent::at(std::size_t pin) const {
    if (_links.contains(pin))
        return _links.at(pin).state;
    return Undefined;
}
