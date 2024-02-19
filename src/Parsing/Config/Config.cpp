/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Config.cpp
*/

#include <utility>
#include <filesystem>
#include <iostream>
#include <cstring>
#include "../../../include/NanoTekSpice.hpp"
#include "Config.hpp"

nts::Config::Config(std::string filename) : _isOpen(false), _filename(std::move(filename)) {
    if (_filename.empty()) {
        std::cerr << program_invocation_name << ": No file provided." << std::endl;
        return;
    }
    if (_filename == "-h" || _filename == "--help")
        nts::NanoTekSpice::help();
    if (!std::filesystem::is_regular_file(_filename)) {
        std::cerr << program_invocation_name << ": " << _filename << ": Not a regular file." << std::endl;
        return;
    }
    _file.open(_filename);
    if (!_file.is_open()) {
        std::cerr << program_invocation_name << ": " << _filename << ": " << std::strerror(errno) << "." << std::endl;
        return;
    }
    _isOpen = true;
}

bool nts::Config::isOpen() const {
    return _isOpen;
}

std::ifstream &nts::Config::getFile() {
    return _file;
}

const std::string &nts::Config::getFilename() const {
    return _filename;
}
