//
// Created by Ruslan on 15.09.2023.
//
#include <iostream>

class String__ {
    public:
        static std::string to_string(const int &i)
        {
            return std::to_string(i);
        }
        static std::string to_string(const float &i)
        {
            return std::to_string(i);
        }
        static std::string to_string(const std::string &i) {
            return i;
        }
        static std::string to_string(const char &i)
        {
            return std::to_string(i);
        }
        // TODO: works incorrectly
//         static std::string to_string(char i[])
//         {
//             std::string str = "";
//             str += i;
//             return str;
//         }
        static std::string to_string(const bool &i)
        {
            return std::to_string(i);
        }
};
