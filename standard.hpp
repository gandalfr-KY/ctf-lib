#pragma once

#include "types.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace gandalfr_ctf {

u8 hex_char_to_int(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    throw std::invalid_argument("Invalid hex character");
}

std::string hex_to_ascii(const std::string &hex) {
    if (hex.length() % 2 != 0) {
        throw std::invalid_argument("Hex string must have an even length");
    }

    std::string ascii;
    ascii.reserve(hex.length() / 2);
    for (size_t i = (hex.substr(0, 2) == "0x" ? 2 : 0); i < hex.length();
         i += 2) {
        u8 high = hex_char_to_int(hex[i]);
        u8 low = hex_char_to_int(hex[i + 1]);
        ascii += (high << 4) | low;
    }
    return ascii;
}

} // namespace gandalfr_ctf
