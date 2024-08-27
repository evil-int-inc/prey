//
// Created by Ruslan on 27.08.2024.
//
#include <iostream>
#include <ctime>

class Integer__ {
    public:
        static int to_integer(const time_t &i)
        {
                return +i;
        }
        static int to_integer(const int &i)
        {
            return i;
        }
        static int to_integer(const float &i)
        {
            return +i;
        }
        static int to_integer(const std::string &i) {
            try {
                return std::stoi(i);
            } catch (const std::invalid_argument& e) {
                return 0;
            }
        }
        static int to_integer(const char &i)
        {
            return to_integer(String__::to_string(i));
        }
        static int to_integer(const char *i) {
            std::string std_string(i);
            return to_integer(std_string);
        }
        static int to_integer(const bool &i)
        {
            return +i;
        }
};
