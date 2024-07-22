#pragma once

#include "../types.hpp"

#include <cassert>
#include <cctype>
#include <string>
#include <vector>

namespace gandalfr_ctf {

std::string encode_ROT(const std::string &s, uint8_t proceed) {
    assert(proceed <= 25);
    std::string enc;
    enc.reserve(s.size());
    for (u8 c : s) {
        if (std::isalpha(c)) {
            uint16_t n = c;
            n -= (std::islower(c) ? 'a' : 'A');
            n += proceed;
            n %= 26;
            n += (std::islower(c) ? 'a' : 'A');
            enc += (char)n;
        } else {
            enc += c;
        }
    }
    return enc;
}

std::string decode_ROT(const std::string &s, uint8_t proceed) {
    assert(proceed <= 25);
    return encode_ROT(s, 26 - proceed);
}

} // namespace gandalfr_ctf
