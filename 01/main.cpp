#include "allocator.hpp"
#include <iostream>
#include <string>


enum{
    whole_size = 10,
    word_size = 5
};

int main(){
    Allocator exmp;
    
    exmp.makeAllocator(whole_size);
    char* iter_cur_pos = exmp.alloc(word_size);
    std::string line = "task1";
    for(size_t i = 0; i < line.length(); ++i){
        *(iter_cur_pos + i) = line[i];
    }

    for(size_t i = 0; i < word_size; ++i){
        std::cout << *(iter_cur_pos + i) << std::endl;
    }

    return 0;
}