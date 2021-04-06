#include "parser.h"


void TokenParser::AnalyzeLine(const std::string& text){
    int first = 0;
    int last = -1;
    std::vector <std::string> separate_words;
    size_t i;
    while(isspace(text[first])){
        ++first;
    }
    for(i = first; i < text.length(); ++i){
        if(std::isspace(text[i])){
            last = i;
            if(!std::isspace(text[i - 1])){
                std::string cur_word = text.substr(first, last - first);
                separate_words.push_back(cur_word);
            }
        } else {
            if (i > 1 && std::isspace(text[i - 1])){
                first = i;
            }
        }
    }
    if (!std::isspace(text[i - 1])){
        std::string cur_word = text.substr(first, i - 1 - first);
        separate_words.push_back(cur_word);
    }
    all_func.start_callback(separate_words);

    for(size_t j = 0; j < separate_words.size(); ++j){
        if(IsNumber(separate_words[j])){
            all_func.digital_callback(separate_words[j]);
        } else {
            all_func.symb_callback(separate_words[j]);
        }
    }
    all_func.end_callback(separate_words);
};

// Устанавливаем callback-функцию перед стартом парсинга.
void TokenParser:: SetStartCallback(std::function<void(std::vector <std::string>)>&& func){
    all_func.start_callback = func;
};

// Устанавливаем callback-функцию после окончания парсинга.
void TokenParser:: SetEndCallback(std::function<void(std::vector <std::string>)>&& func){
    all_func.end_callback = func;
};

// Устанавливаем callback-функцию для обработки чисел.
void TokenParser:: SetDigitTokenCallback(std::function<void(std::string)>&& func){
    all_func.digital_callback = func;
};

// Тут другие методы для установки callback-функций.
void TokenParser:: SetWordTokenCallback(std::function<void(std::string)>&& func){
    all_func.symb_callback = func;
};

int TokenParser:: IsNumber(std::string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
};

