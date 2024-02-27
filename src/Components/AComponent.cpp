/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent.cpp
*/

#include <functional>
#include <utility>
#include "AComponent.hpp"

const std::string nts::AComponent::Error::ERRORS[] = {
        "Pin out of range in link",
        "Pin cannot be linked in link",
        "Pin already linked in link"
};

nts::AComponent::Error::Error(std::string message) : _message(std::move(message)) {}

const char *nts::AComponent::Error::what() const noexcept {
    return _message.c_str();
}

nts::AComponent::AComponent(nts::Component type, std::size_t maxPin, Tristate state) : _state(state), _type(type), _maxPin(maxPin) {}

void nts::AComponent::simulate([[maybe_unused]] std::size_t tick) {}

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
void nts::AComponent::insert(std::size_t pin, IComponent &other, std::size_t otherPin) {
    Link link = {other, otherPin, other.compute(otherPin)};
    _links.insert(std::make_pair(pin, link));
}

/**
 * @brief Link a pin of the current component to another component.<br>
 * It also links the other component to the current component.
 *
 * If the pin is already linked or is invalid, it throws an error.
 *
 * @param pin The pin of the current component.
 * @param other The other component.
 * @param otherPin The pin of the other component.
 */
void nts::AComponent::setLink(std::size_t pin, std::unique_ptr<IComponent> &other, std::size_t otherPin) {
    if (pin == 0 || pin > _maxPin || otherPin == 0 || otherPin > other->getMaxPin())
        throw Error(Error::ERRORS[Error::PinOutOfRange]);

    const std::vector<std::size_t> &otherExcludedPins = other->getExcludedPins();
    if (std::find(_excludedPins.begin(), _excludedPins.end(), pin) != _excludedPins.end() ||
        std::find(otherExcludedPins.begin(), otherExcludedPins.end(), otherPin) != otherExcludedPins.end())
        throw Error(Error::ERRORS[Error::PinExcluded]);

    const std::map<std::size_t, Link> &otherLinks = other->getLinks();
    if (std::find_if(_links.begin(), _links.end(), [pin](const std::pair<std::size_t, Link> &link) {
            return link.first == pin;
        }) != _links.end() ||
        std::find_if(otherLinks.begin(), otherLinks.end(), [otherPin](const std::pair<std::size_t, Link> &link) {
            return link.first == otherPin;
        }) != otherLinks.end())
        throw Error(Error::ERRORS[Error::PinAlreadyLinked]);

    insert(pin, *other, otherPin);
    other->insert(otherPin, *this, pin);
}

void nts::AComponent::updateState(nts::Tristate state) {
    _nextState = state;
}

char nts::AComponent::getValue() const {
    switch (_state) {
        case True:
            return '1';
        case False:
            return '0';
        default:
            return 'U';
    }
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

nts::Tristate nts::AComponent::at(std::size_t pin) const {
    if (_links.contains(pin)) {
        const Link &link = _links.at(pin);

        return link.other.compute(link.otherPin);
    }
    return Undefined;
}

nts::Component nts::AComponent::getType() const {
    return _type;
}

const std::map<std::size_t, nts::Link> &nts::AComponent::getLinks() const {
    return _links;
}

std::size_t nts::AComponent::getMaxPin() const {
    return _maxPin;
}

const std::vector<std::size_t> &nts::AComponent::getExcludedPins() const {
    return _excludedPins;
}
