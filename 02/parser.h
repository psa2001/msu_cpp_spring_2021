#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cctype>

inline void empty_for_line(std::vector <std::string>){return;};
inline void empty_for_word(std::string){return;};

class ParserFunc{
public:
    std::function<void(std::vector <std::string>)> start_callback = empty_for_line;
    std::function<void(std::vector <std::string>)> end_callback = empty_for_line;
    std::function<void(std::string)> digital_callback = empty_for_word;
    std::function<void(std::string)> symb_callback = empty_for_word;
};

class TokenParser
{
private:
    ParserFunc all_func;
public:
    TokenParser() = default;

    void AnalyzeLine(const std::string& text);

    // Устанавливаем callback-функцию перед стартом парсинга.
    void SetStartCallback(std::function<void(std::vector <std::string>)>&& func);

    // Устанавливаем callback-функцию после окончания парсинга.
    void SetEndCallback(std::function<void(std::vector <std::string>)>&& func);

    void SetDigitTokenCallback(std::function<void(std::string)>&& func);
    // Тут другие методы для установки callback-функций.
    void SetWordTokenCallback(std::function<void(std::string)>&& func);

    int IsNumber(std::string s);
};