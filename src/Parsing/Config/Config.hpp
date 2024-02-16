/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Config.hpp
*/

#ifndef NANOTEKSPICE_CONFIG_HPP_
#define NANOTEKSPICE_CONFIG_HPP_

#include <fstream>

namespace nts {
    class Config {
    public:
        explicit Config(const char *filename);

        [[nodiscard]] bool isOpen() const;

        [[nodiscard]] std::ifstream &getFile();

        [[nodiscard]] const std::string &getFilename() const;

    private:
        bool _isOpen;
        std::ifstream _file;
        const std::string _filename;
    };
}

#endif /* !NANOTEKSPICE_CONFIG_HPP_ */
