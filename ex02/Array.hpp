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

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {    
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T>::Array(unsigned int n): _data(nullptr), _size(n) {
    if (n == 0) {
        return ;
    }
    _data = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other): _data(nullptr), _size(other._size) {
    if (_size == 0) {
        return ;
    }
    _data = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this == &other)
        return *this;

    delete[] _data;
    _size = other._size;
    _data = (_size == 0) ? nullptr : new T[_size];

    for (size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i];

    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
    if (i >= _size)
        throw std::exception();
    return _data[i];
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
    if (i >= _size)
        throw std::exception();
    return _data[i];
}

#endif