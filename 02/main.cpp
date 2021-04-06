#include "parser.h"

void print_digit(std::string s){
    std::cout << "digit " << s << std::endl;
}

void print_symb(std::string s){
    std::cout << "symbol_word " << s << std::endl;
}

void begin(std::vector<std::string> s){
    for(size_t i = 0; i< s.size(); ++i){
        std::cout << "before num " << i << " " << s[i] << std::endl;
    }
}

void end(std::vector<std::string> s){
    for(size_t i = 0; i < s.size(); ++i){
        std::cout << "after num " << i << " " << s[i] << std::endl;
    }
}

int main(){
    try{
        //1 example
        {
            TokenParser a;
            a.SetDigitTokenCallback(print_digit);
            a.AnalyzeLine("123 3    2           23 wefd 3 \n 23");
        }
        //2 example
        {
            TokenParser a;
            a.SetDigitTokenCallback(print_symb);
            a.AnalyzeLine("123 3    2           23 wefd 3 \n 23");
        }
        //3 example
        {
            TokenParser a;
            std::string cur;
            std::cin >> cur;
            a.AnalyzeLine(cur);
        }
        //4 example
        {
            TokenParser a;
            a.SetStartCallback(begin);
            a.AnalyzeLine("123 3    2           23 wefd 3 \n 23");
        }
        //5 example
        {
            TokenParser a;
            std::string cur;
            std::cin >> cur;
            a.SetEndCallback(end);
            a.AnalyzeLine(cur);
        }
    }  
    catch(...){
        std::cout << "Mistake" << std::endl;
        return 1;
    }
    return 0;
}
