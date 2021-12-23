#pragma once
#include "MyString.h"


// Конструктор по умолчанию
    BMSTU::string::string() {
        _str_ptr = new char[1];
        *_str_ptr = '\0';
        _size_str = 1;
    }

// Конструктор создающий строку длинной n символов
    BMSTU::string::string(size_t size) {
        _str_ptr = new char[size + 1];
        _fill(_str_ptr, size, ' ');
        *(_str_ptr + size) = '\0';
        _size_str = size + 1;
    }

// Конструктор принимающий C-style строку
    BMSTU::string::string(const char *c_str) {
        _size_str = _strlen(c_str);
        _str_ptr = new char[_size_str];
        memcpy(_str_ptr, c_str, _size_str);
        *(_str_ptr + _size_str - 1) = '\0';
    }

// Конструктор копирования
    BMSTU::string::string(const BMSTU::string &other_string) {
        _size_str = other_string.size() + 1;
        _str_ptr = new char[_size_str];
        memcpy(_str_ptr, other_string._str_ptr, _size_str);
    }

// Оператор строковой конкатенации
    BMSTU::string& BMSTU::string::operator+=(const BMSTU::string &other_string) {
        int tmp_size = _size_str + other_string._size_str - 1;
        char *tmp_str = new char[tmp_size];

        memcpy(tmp_str, _str_ptr, _size_str);

        memcpy(tmp_str + _size_str - 1, other_string._str_ptr, other_string.size());

        delete[] _str_ptr;
        _size_str = tmp_size;
        _str_ptr = tmp_str;

        return *this;
    }

// Оператор строковой конкатенации
    BMSTU::string BMSTU::operator+(BMSTU::string other_string, const BMSTU::string &another_string) {
        return other_string.operator+=(another_string);
    }

// Оператор присваивания
    BMSTU::string& BMSTU::string::operator=(const BMSTU::string &other_string) {
        _size_str = other_string._size_str;
        _str_ptr = new char[_size_str];
        memcpy(_str_ptr, other_string._str_ptr, other_string._size_str);
        return *this;
    }

// Оператор присваивания
    BMSTU::string& BMSTU::string::operator=(const char *other_c_str) {
        _size_str = _strlen(other_c_str);
        _str_ptr = new char[_size_str];
        memcpy(_str_ptr, other_c_str, _size_str);
        return *this;
    }

    bool BMSTU::operator==(const BMSTU::string &lhs, const BMSTU::string &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        for (int i = 0; i < lhs.size(); ++i) {
            if (*(lhs._str_ptr + i) != *(rhs._str_ptr + i))
                return false;
        }
        return true;
    }

    bool BMSTU::operator==(const BMSTU::string &lhs, const char *rhs) {
        return lhs==BMSTU::string(rhs);
    }

    bool BMSTU::operator==(const char *lhs, const BMSTU::string &rhs) {
        return BMSTU::string(lhs)==rhs;
    }

// Оператор вывода в поток
    std::ostream &BMSTU::operator<<(std::ostream &out, const BMSTU::string &item) {
        char *tmp = item._str_ptr;
        return out << (tmp ? tmp : "");
    }


// Деструктор
    BMSTU::string::~string() {
        delete[] _str_ptr;
        _str_ptr = nullptr;
    }


    void BMSTU::string::_fill(char *str, size_t size, char value) {
        for (size_t i = 0; i < size; i++) {
            *(str + i) = value;
        }
    }

    size_t BMSTU::string::_strlen(const char *str) {
        size_t ans = 0;
        while (*str) {
            ans++;
            str++;
        }
        return (ans + 1);
    }


    const char *BMSTU::string::c_str() const {
        char *tmp = new char[_size_str];
        memcpy(tmp, _str_ptr, _size_str);
        return tmp;
    }

// возвращает указатель на первый элемент
    char *BMSTU::string::data() {
        return _str_ptr;
    }

    const size_t BMSTU::string::size() const {
        return _size_str - 1;
    }

    void BMSTU::swap(BMSTU::string &first, BMSTU::string &second) {
        char *tmp = first._str_ptr;
        first._str_ptr = second._str_ptr;
        second._str_ptr = tmp;
    }