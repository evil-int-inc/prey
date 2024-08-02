//
// Created by Ruslan on 08.04.2024.
//
// TODO: remove '#include <iostream>'
#include <iostream>

template <typename _D>
class Root__ {
    public:
        /** exit | error | success */
        std::string type;
        /** compilation | runtime */
        std::string subtype;
        /** -1 - unknown */
        int code;
        _D data;
        Root__(std::string const type, std::string const subtype, _D const& _d, int const code = -1)
        {
            this->type = type;
            this->subtype = subtype;
            this->data = _d;
            this->code = code;
        }
        ~Root__()
        {
        }
};