//
// Created by Ruslan on 08.04.2024.
//
// TODO: remove '#include <iostream>'
#include <iostream>
#include <optional>

class ErrorData__ {
public:
    std::string name;
    std::string message;
    std::string filename;
    std::string filepath;
    int line;

    ErrorData__(std::string const message, std::string const filename, std::string const filepath, int const line) {
        this->name = message;
        this->message = message;
        this->filename = filename;
        this->filepath = filepath;
        this->line = line;
    }

    ~ErrorData__() {
    }
};

class MessageErrorData__ {
public:
    std::string message;

    MessageErrorData__(std::string const message) {
        this->message = message;
    }

    ~MessageErrorData__() {
    }
};

class Error__ : public Root__<ErrorData__ *> {
public:
    Error__(
            std::string const subtype,
            std::string const message,
            std::string const filename,
            std::string const filepath,
            std::optional<int> const code_,
            std::optional<int> const line_) : Root__("error", subtype, new ErrorData__(message, filename, filepath, line_.value_or(-1)), code_.value_or(-1)) {
    }

    ~Error__() {
    }
};

class MessageError__ {
public:
    /** exit | error | success */
    std::string type;
    /** compilation | runtime */
    std::string subtype;
    /** -1 - unknown */
    int code;
    std::string message;
    std::string mapCode;

    std::string printable() {
        return std::string("MessageError {\n  type: \"error\",\n  subtype: \"runtime\",\n  message: \"") + message +
               std::string("\",\n  mapCode: \"") + mapCode + std::string("\",\n  code: ") + std::to_string(code) +
               std::string("\n}");
    }

    MessageError__(
            std::string const message,
            std::optional<std::string> const mapCode_,
            std::optional<int> const code_) {
        const std::string mapCode = mapCode_.value_or("-1");
        const int code = code_.value_or(2);
        this->type = "error";
        this->subtype = "runtime";
        this->message = message;
        this->mapCode = mapCode;
        this->code = code;
    }

    ~MessageError__() {
    }
};
