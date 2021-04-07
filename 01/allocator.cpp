#include "allocator.hpp"

void Allocator::makeAllocator(size_t maxSize){
    if(arr != nullptr){
        delete []arr;  
    }
    if(maxSize == 0){
        arr = nullptr;
    } else {
        arr = new char [maxSize];
        arr_size = maxSize;
        offset = 0;
    }
}

char* Allocator::alloc(size_t asked_size){
    size_t freespace = arr_size -  offset;
    if(asked_size <= freespace && arr_size != 0){
        size_t oldoffset = offset;
        offset += asked_size;
        return arr + oldoffset;
    } else {
        return nullptr;
    }
}

void Allocator::reset(){
    offset = 0;
}


Allocator::~Allocator(){
    delete []arr;
}