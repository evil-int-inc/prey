//
// Created by Ruslan on 27.08.2024.
//
#include <iostream>
#include <ctime>

class Boolean__ {
public:
    static bool to_boolean(const time_t &i) {
        return i;
    }

    static bool to_boolean(const int &i) {
        return i;
    }

    static bool to_boolean(const float &i) {
        return i;
    }

    static bool to_boolean(const std::string &i) {
        if (i == "") return false;

        return true;
    }

    static bool to_boolean(const char &i) {
        return to_boolean(String__::to_string(i));
    }

    static bool to_boolean(const char *i) {
        std::string std_string(i);
        return to_boolean(std_string);
    }

    static bool to_boolean(const bool &i) {
        return i;
    }
};
