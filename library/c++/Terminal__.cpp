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
            static void print(const Date__ &date) {
                Terminal__::print(Date__::toISOString(date));
            }
            template<typename _V>
            static void print(Vector__<_V> &v) {
                std::string s = "[\n";
                for (int i = 0; i < v.size(); ++i) {
                    s += "  " + String__::to_string(v.get(i)) + ",\n";
                }
                Terminal__::print(s + "]");
            }
            template<typename _K, typename _V>
            static void print(const Map__<_K, _V> &m) {
                std::string s = "[\n";
                for (std::pair<std::string, int> pair__ : m.m__)
                {
                    _K k = pair__.first;
                    _V v = pair__.second;
                    s += "  [" + String__::to_string(k) + ", " + String__::to_string(v) + "],\n";
                }
                Terminal__::print(s + "]");
            }
};
