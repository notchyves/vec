#pragma once

#include <cstddef>
#include <memory.h>
#include <stdlib.h>
#include <initializer_list>
#include <stdexcept>

namespace chyves
{
    template <typename T, size_t N = 0>
    class vec
    {
    private:
        size_t size;
        T *data;

    public:
        vec() : size(0), data(nullptr) {}

        vec(std::initializer_list<T> list) : size(list.size()), data(new T[size])
        {
            if (N != 0 && list.size() > N)
            {
                throw std::invalid_argument("Initializer list size exceeds fixed size");
            }
            std::copy(list.begin(), list.end(), data);
        }

        ~vec()
        {
            delete[] data;
        }

        const T &get(size_t index) const
        {
            if (index < size)
            {
                return data[index];
            }
            throw std::out_of_range("Index out of bounds");
        }

        void set(size_t index, const T &value)
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of bounds");
            }

            data[index] = value;
        }

        const size_t getSize()
        {
            return size;
        }

        void remove(size_t index)
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of bounds");
            }

            for (size_t i = index; i < size - 1; ++i)
            {
                data[i] = data[i + 1];
            }

            --size;

            T *newData = new T[size];
            std::copy(data, data + size, newData);

            delete[] data;
            data = newData;
        }

        void clear()
        {
            delete[] data;
            size = 0;
            data = nullptr;
        }

        void push_back(const T &value)
        {
            T *newData = new T[size + 1];

            if (data)
            {
                std::copy(data, data + size, newData);
                delete[] data;
            }

            newData[size] = value;

            ++size;

            data = newData;
        }

        void pop_back()
        {
            if (size > 0)
            {
                --size;

                T *newData = new T[size];
                std::copy(data, data + size, newData);

                delete[] data;
                data = newData;
            }
        }

        // Overloaded operators for arithmetic operations
        vec<T> operator+(const vec<T> &other) const
        {
            if (size != other.size)
                throw std::invalid_argument("Vector sizes must match for addition");

            vec<T> result;

            for (size_t i = 0; i < size; ++i)
                result.push_back(data[i] + other.data[i]);

            return result;
        }

        vec<T> operator-(const vec<T> &other) const
        {
            if (size != other.size)
                throw std::invalid_argument("Vector sizes must match for subtraction");

            vec<T> result;

            for (size_t i = 0; i < size; ++i)
                result.push_back(data[i] - other.data[i]);

            return result;
        }

        vec<T> operator*(const T &scalar) const
        {
            vec<T> result;

            for (size_t i = 0; i < size; ++i)
                result.push_back(data[i] * scalar);

            return result;
        }

        vec<T> operator/(const T &scalar) const
        {
            if (scalar == 0)
                throw std::invalid_argument("Division by zero");

            vec<T> result;

            for (size_t i = 0; i < size; ++i)
                result.push_back(data[i] / scalar);

            return result;
        }
    };

    // custom types for use
    typedef chyves::vec<int> vec_int;
    typedef chyves::vec<int, 2> vec2_int;
    typedef chyves::vec<int, 3> vec3_int;
    typedef chyves::vec<int, 4> vec4_int;

    typedef chyves::vec<float> vec_float;
    typedef chyves::vec<float, 2> vec2_float;
    typedef chyves::vec<float, 3> vec3_float;
    typedef chyves::vec<float, 4> vec4_float;
    
    typedef chyves::vec<bool> vec_bool;
    typedef chyves::vec<bool, 2> vec2_bool;
    typedef chyves::vec<bool, 3> vec3_bool;
    typedef chyves::vec<bool, 4> vec4_bool;

    typedef chyves::vec<const char*> vec_cchar;
    typedef chyves::vec<const char*, 2> vec2_cchar;
    typedef chyves::vec<const char*, 3> vec3_cchar;
    typedef chyves::vec<const char*, 4> vec4_cchar;
};
