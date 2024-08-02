//
// Created by Ruslan on 15.09.2023.
//
#include <iostream>

class Terminal__ {
    public:
        static void print(const int &a)
        {
            std::cout << a << std::endl;
        }
        static void print(const float &a)
        {
            std::cout << a << std::endl;
        }
        static void print(const std::string &a) {
            std::cout << a << std::endl;
        }
        static void print(const char *a) {
            std::cout << a << std::endl;
        }
        static void print(const char &a) {
            std::cout << a << std::endl;
        }
        static void print(const bool &a) {
            std::cout << a << std::endl;
        }
};