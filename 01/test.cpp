#include "allocator.hpp"

void CheckNullptr1(){
    Allocator allocator;
    allocator.makeAllocator(2);
    char* cur_point = allocator.alloc(3);
    assert(cur_point == nullptr);
};

void CheckNullptr2(){
    Allocator allocator;
    allocator.makeAllocator(2);
    char* cur_point = allocator.alloc(2);
    assert(cur_point != nullptr);
    cur_point = allocator.alloc(1);
    assert(cur_point == nullptr);
};

void CheckNoNullptr(){
    Allocator allocator;
    allocator.makeAllocator(10);
    char* cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
};

void CheckReset(){
    Allocator allocator;
    allocator.makeAllocator(10);
    char* cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
    allocator.reset();
    cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
}


void CheckResetNullptr(){
    Allocator allocator;
    allocator.makeAllocator(10);
    char* cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
    allocator.reset();
    cur_point = allocator.alloc(11);
    assert(cur_point != nullptr);
}

int main(){
    return 0;
}