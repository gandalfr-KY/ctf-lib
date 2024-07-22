#pragma once

#include "../types.hpp"

#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>

namespace gandalfr_ctf {

namespace internal {

u8 ascii_to_base64(u8 c) {
    if (std::isalpha(c) && std::isupper(c)) {
        return c - 'A';
    } else if (std::isalpha(c) && std::islower(c)) {
        return c - 'a' + 26;
    } else if (std::isdigit(c)) {
        return c - '0' + 52;
    } else if (c == '+') {
        return 62;
    } else if (c == '/') {
        return 63;
    } else {
        throw std::invalid_argument("Invalid Base64 character");
    }
}

u8 base64_to_ascii(u8 b) {
    if (b < 26) {
        return 'A' + b;
    } else if (b < 52) {
        return 'a' + (b - 26);
    } else if (b < 62) {
        return '0' + (b - 52);
    } else if (b == 62) {
        return '+';
    } else if (b == 63) {
        return '/';
    } else {
        throw std::invalid_argument("Invalid byte for Base64");
    }
}

} // namespace internal

std::string encode_base64(const std::string &s) {
    static const char padding_char = '=';
    std::string result;
    i32 val = 0;
    i32 valb = -6;

    for (u8 c : s) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            result.push_back(internal::base64_to_ascii((val >> valb) & 0x3F));
            valb -= 6;
        }
    }
    if (valb > -6)
        result.push_back(
            internal::base64_to_ascii(((val << 8) >> (valb + 8)) & 0x3F));
    while (result.size() & 0x3) // % 4
        result.push_back(padding_char);
    return result;
}

std::string decode_base64(const std::string &s) {
    static const char padding_char = '=';
    i32 T[256];
    std::fill(T, T + 256, -1);
    for (int i = 0; i < 64; i++)
        T[internal::base64_to_ascii(i)] = i;
    std::string result;
    i32 val = 0;
    i32 valb = -8;

    for (u8 c : s) {
        if (T[c] == -1)
            break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            result.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return result;
}

} // namespace gandalfr_ctf
