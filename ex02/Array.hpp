#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>
#include <exception>

template<typename T> class Array {
    private:
        T*      _data;
        size_t  _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        
        size_t size() const;

        T& operator[](size_t i);
        const T& operator[](size_t i) const;
};

#endif