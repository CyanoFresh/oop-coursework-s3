#ifndef COURSEWORK_ARRAY_H
#define COURSEWORK_ARRAY_H

#include <iostream>
#include <algorithm>

template<typename T>
class Array {
    T *data;
    size_t _size;
    size_t _capacity;
public:

    void resize() {
        if (_size == _capacity) {
            std::size_t newCapacity = std::max(2.0, _capacity * 1.5);
            reserve(newCapacity);
        }
    }

    void resize(int newCapacity);

    bool empty() {
        return _size == 0;
    }

    unsigned int size() const {
        return _size;
    }

    void clear() {
        if (_size > 0) {
            delete[] data;
            _size = 0;
        }
    }

    void reserve(int reserve_size) {
        if (_size > reserve_size) {
            return;
        } else {
            T *newData = new T[reserve_size];
            if (_size > 0) {
                for (int i = 0; i < _size; i++) {
                    newData[i] = data[i];
                }
            }
            data = newData;
        }
        _capacity = reserve_size;
    }

    void assign(const T &elem) {
        resize();
        T *newData = new T[_size + 1];
        if (_size > 0) {
            for (size_t i = 0; i < _size; i++)
                newData[i] = data[i];
            delete[] data;
        }
        newData[_size] = elem;
        data = newData;
        _size++;
    }

    void remove_last() {
        (reinterpret_cast<T *>(data)[_size-- - 1]).~T();
    }

    void swap(Array &other) {
        using std::swap;
        swap(_capacity, other._capacity);
        swap(_size, other._size);
        swap(data, other.data);
    }

    void remove(int pos) {
        for (size_t i = pos + 1; i < _size; i++) {
            data[i - 1] = data[i];
        }
        remove_last();
    }

    ~Array();

    Array();

    Array(const Array &other) : _size(other._size), data(new T[other._size]), _capacity(other._capacity) {
        for (int i = 0; i < _size; i++) {
            data[i] = other.data[i];
        }
    }

    T &at(int i) {
        try {
            if (i < 0 || i > _size - 1)
                throw std::logic_error("Bounds error");
            return data[i];
        } catch (exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    T &operator[](int i) {
        return at(i);
    }

    Array<T> &operator=(Array<T> &rhs) {
        rhs.swap(*this);
        return *this;
    }

    explicit Array(const int reserve_size) : _size(0), data(new T[reserve_size]), _capacity(reserve_size) {}

    friend std::ostream &operator<<(std::ostream &stream, const Array<T> &to_print) {
        try {
            //stream << to_print.size() << std::endl;
            for (int i = 0; i < to_print._size; ++i) {
                stream << to_print.data[i];
                stream << std::endl;
            }
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        return stream;
    }

    friend std::istream &operator>>(std::istream &stream, Array<T> &to_read) {
        try {
            while (!stream.eof()) {
                T item;
                stream >> item;
                to_read.assign(item);
            }
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        return stream;
    }

};

template<typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
Array<T>::Array() : _size(0), _capacity(10000), data(new T[1]) {}

#endif //COURSEWORK_ARRAY_H
