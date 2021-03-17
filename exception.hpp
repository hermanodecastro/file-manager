#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

using namespace std;

class NoSuchFileException : public exception {
    private:
        string message;

    public:
        NoSuchFileException();
        const char *what() const noexcept override;
};

class NoSuchIndexException : public exception {
    private:
        string message;

    public:
        NoSuchIndexException();
        const char *what() const noexcept override;
};

#endif
