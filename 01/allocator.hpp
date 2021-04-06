#pragma once
#include <iostream>
#include <cassert>


class Allocator
{
private:
    size_t offset;
    char* arr = nullptr;
    size_t arr_size;
public:
    Allocator() = default;
    void makeAllocator(size_t maxSize);
    char* alloc(size_t asked_size);
    void reset();
    ~Allocator();
};


