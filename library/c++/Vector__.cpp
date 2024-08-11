//
// Created by Ruslan on 11.03.2024.
//
#include <vector>

template <typename _T>
class Vector__ {
    public:
        std::vector<_T> v__;
        int size()
        {
            return this->v__.size();
        }
        _T get(const int index)
        {
            return this->v__[index];
        }
        void set(const int index, const _T value)
        {
            this->v__[index] = value;
        }
        Vector__(std::vector<_T> v)
        {
            this->v__ = v;
        }
        ~Vector__()
        {
        }
};