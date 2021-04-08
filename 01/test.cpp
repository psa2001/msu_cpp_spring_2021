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
    assert(cur_point == nullptr);
}

void ManyMakeAllocator(){
    try{
        Allocator allocator;
        allocator.makeAllocator(10);
        allocator.makeAllocator(11);
        allocator.makeAllocator(8);
        allocator.makeAllocator(1);
    } 
    catch(...){
        //any error/mistake
        assert(1 == 0);
    }
}


void BoundaryCaseReset(){
    Allocator allocator;
    allocator.makeAllocator(10);
    char* cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
    cur_point = allocator.alloc(1);
    assert(cur_point == nullptr);
    allocator.reset();
    cur_point = allocator.alloc(10);
    assert(cur_point != nullptr);
}

void AllocBeforeMake(){
    Allocator allocator;
    char* cur_point = allocator.alloc(10);
    assert(cur_point == nullptr);
}

void MakeAllocatorZero(){
    Allocator allocator;
    allocator.makeAllocator(0);
    char* cur_point = allocator.alloc(1);
    assert(cur_point == nullptr);
}

int main(){
    CheckNullptr1();
    CheckNullptr2();
    CheckNoNullptr();
    CheckReset();
    CheckResetNullptr();
    ManyMakeAllocator();
    BoundaryCaseReset();
    AllocBeforeMake();
    MakeAllocatorZero();
    return 0;
}