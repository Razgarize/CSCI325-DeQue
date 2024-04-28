#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

Deque::Deque() 
{
    blockmap = new Deque*[10];
    map_capacity = 10;
    map_size = 0;
    front = blockmap[0];
}
Deque::~Deque() 
{
    delete[] blockmap;
}
void Deque::push_front() 
{
    if (map_size == map_capacity) {
        Deque **temp = new Deque*[map_capacity * 2];
        for (int i = 0; i < map_size; i++) {
            temp[i] = blockmap[i];
        }
        delete[] blockmap;
        blockmap = temp;
        map_capacity *= 2;
    }
    Deque *temp = new Deque();
    blockmap[map_size] = temp;
    map_size++;
}
Deque& Deque::operator[](int index) 
{
    return *blockmap[index];
}