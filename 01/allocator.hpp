#pragma once
#include <iostream>
#include <cassert>


class Allocator
{
private:
    size_t offset = 0;
    char* arr = nullptr;
    size_t arr_size = 0;
public:
    Allocator() = default;
    void makeAllocator(size_t maxSize);
    char* alloc(size_t asked_size);
    void reset();
    ~Allocator();
};


