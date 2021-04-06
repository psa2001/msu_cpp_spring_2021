#include "allocator.hpp"

void Allocator::makeAllocator(size_t maxSize){
    if(arr != nullptr){
        delete arr;  
    }
    arr = static_cast<char *>(new char [maxSize]);
    arr_size = maxSize;
    offset = 0;
}

char* Allocator::alloc(size_t asked_size){
    size_t freespace = arr_size -  offset;
    if(asked_size <= freespace){
        offset += asked_size;
        return arr + offset;
    } else {
        return nullptr;
    }
}

void Allocator::reset(){
    offset = 0;
}


Allocator::~Allocator(){
    delete arr;
}