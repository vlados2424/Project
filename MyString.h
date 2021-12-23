#pragma once
#include <cstddef>
#include <cstring>
#include <iostream>


namespace BMSTU {
    class string {
    public:

        // Конструктор по умолчанию
        explicit string();

        // Конструктор создающий строку длинной n символов
        string(size_t size);

        // Конструктор принимающий C-style строку
        string(const char *c_str);

        // Конструктор копирования
        string(const BMSTU::string &other_string);

        // Оператор строковой конкатенации
        string &operator+=(const BMSTU::string &other_string);

        friend string operator+(BMSTU::string other_string, const BMSTU::string &another_string);

        // Оператор присваивания
        string &operator=(const BMSTU::string &other_string);

        // Оператор присваивания
        string &operator=(const char *other_c_str);

        friend bool operator==(const BMSTU::string &lhs, const BMSTU::string &rhs);

        friend bool operator==(const BMSTU::string &lhs, const char *rhs);

        friend bool operator==(const char *lhs, const BMSTU::string &rhs);

        // Оператор вывода в поток
        friend std::ostream &operator<<(std::ostream &out, const string &item);

        // Деструктор
        ~string();

        const char *c_str() const;
        char *data();
        const size_t size() const;
        friend void swap(BMSTU::string &first, BMSTU::string &second);


    private:
        char *_str_ptr;
        size_t _size_str;
        void _fill(char *str, size_t size, char value);
        static size_t _strlen(const char *str);
    };
}