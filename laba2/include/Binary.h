#ifndef BINARY_H
#define BINARY_H

#include <string>
#include <initializer_list>
#include <stdexcept>

class Binary {
private:
    unsigned char* data;
    size_t size;
    
    void copy(const Binary& other);
    void move(Binary&& other) noexcept;

public:
    Binary();
    Binary(const size_t & n, unsigned char t = 0);
    Binary(const std::initializer_list<unsigned char> &t);
    Binary(const std::string &t);
    Binary(const Binary& other);
    Binary(Binary&& other) noexcept;

    virtual ~Binary() noexcept;
    
    Binary& operator=(const Binary& other);
    Binary& operator=(Binary&& other) noexcept;

    Binary add(const Binary& other) const;
    Binary subtract(const Binary& other) const;
    Binary copyBinary() const;

    bool equals(const Binary& other) const;
    bool less(const Binary& other) const;
    bool greater(const Binary& other) const;
    
    size_t getSize() const;
    unsigned char getDigit(size_t index) const;
    std::string toString() const;
};

#endif
