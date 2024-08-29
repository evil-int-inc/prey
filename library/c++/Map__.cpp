//
// Created by Ruslan on 11.03.2024.
//
#include <map>

template <typename _K, typename _V>
class Map__ {
    public:
        std::map<_K, _V> m__;
        int size()
        {
            return m__.size();
        }
        _V get(const _K key)
        {
            return m__[key];
        }
        void set(const _K key, const _V value)
        {
            m__[key] = value;
        }
        Map__()
        {
            this->m__ = std::map<_K, _V>();
        }
        ~Map__()
        {
        }
};
