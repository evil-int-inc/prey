//
// Created by Ruslan on 11.03.2024.
//
#include <map>

template <typename _K, typename _V>
class Map__ {
    public:
        std::map<_K, _V>* m__;
        int size()
        {
            return this->m__.size;
        }
        _V get(const _K key)
        {
            return this->m__.get(key);
        }
        void set(const _K key, const _V value)
        {
            this->m__.set(key, value);
        }
        Map__()
        {
            this->m__ = new std::map<_K, _V>();
        }
        ~Map__()
        {
        }
};