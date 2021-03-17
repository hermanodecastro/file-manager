#include <iostream>
#include "exception.hpp"

NoSuchFileException::NoSuchFileException() {
    this->message = "Error: No such file or directory";
}

const char *NoSuchFileException::what() const noexcept {
    return this->message.c_str();
}

NoSuchIndexException::NoSuchIndexException() {
    this->message = "Error: No such index";
}

const char *NoSuchIndexException::what() const noexcept {
    return this->message.c_str();
}
