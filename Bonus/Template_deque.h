#ifndef DEQUE_Bonus
#define DEQUE_Bonus
#include <iostream>

template <typename DequeT>
class Deque
{
private:
    DequeT **blockmap;   // Pointer to the map of pointers to the blocks
    DequeT *RearPtr;     // points to the last element in the deque
    DequeT *FrontPtr;    // points to the first element in the deque
    DequeT *MapFrontPtr; // Front most pointer in the map
    DequeT *MapRearPtr;  // Rear most pointer in the map
    int capacity;
    int BlockElementCounter; // Counter for the number of elements in all the blocks.
    int MapSize;
    const static int BLOCK_SIZE = 5; // Size of each block in the arrays. This is a constant value that will never change for simplicity.
    void MapResize();

public:
    Deque();
    ~Deque();
    void push_element_front(DequeT value);
    void push_element_back(DequeT value);
    void pop_front();
    void push_back(DequeT value);
    void pop_back();
    void get_front();
    void get_back();
    void empty();
    DequeT get_capacity();
    DequeT get_MapSize();
    void MapResizeHelper();
    DequeT &operator[](DequeT index);
    void MoveRearPtrRight();
    void MoveFrontPtrLeft();
    void NewBlockFront();
    void NewBlockRear();

    // DEBUGGER SECTION:
    void printBlockMap();
};

// Implimentation of the templated Deque class

template <typename DequeT>
Deque<DequeT>::Deque() // Constructor
{
    capacity = 10;                     // Max size of the map
    MapSize = 0;                       // Number of block pointers in the map.
    blockmap = new DequeT *[capacity]; // Creates the map for the pointers to the blocks. Each block is a pointer to an array of DequeT. It is empty.
    BlockElementCounter = 0;           // Number of elements in the blocks
    RearPtr = &blockmap[0][0];         // Points to the last element in the deque. 
    FrontPtr = &blockmap[0][0];        // Points to the first element in the deque. Starts at the same place as RearPtr.
    MapFrontPtr = NULL;                // Front most pointer in the map
    MapRearPtr = NULL;                 // Rear most pointer in the map
}


template <typename DequeT>
Deque<DequeT>::~Deque() // Destructor
{
    delete[] blockmap;
}

template <typename DequeT>
void Deque<DequeT>::NewBlockRear()
{
    if (blockmap == nullptr) // If the map is empty
    {
        blockmap = new DequeT *[capacity]; // Create a new map of pointers to the blocks
    }
    if (MapSize >= capacity) // If the map is full
    {
        MapResize(); // Resize the map to double the capacity
    }
    blockmap[MapSize] = new DequeT[BLOCK_SIZE]; // Create a new block of size BLOCK_SIZE
    MapSize++;                                  // Increment the MapSize of the map
}

template <typename DequeT>
void Deque<DequeT>::push_element_front(DequeT value)
{
    if (FrontPtr == blockmap[0]) // If the FrontPtr is at the front of the block
    {
        NewBlockFront(); // Create a new block at the front
        FrontPtr = &blockmap[MapSize - 1][BLOCK_SIZE - 1]; // Set the FrontPtr to the last element in the new block
        *FrontPtr = value; // Set the value of the FrontPtr to the value passed in
        BlockElementCounter++; // Increment the number of elements in the blocks
    }
    else
    {
        FrontPtr--; // Move the FrontPtr to the left
        *FrontPtr = value; // Set the value of the FrontPtr to the value passed in
        BlockElementCounter++; // Increment the number of elements in the blocks
    }
}

template <typename DequeT>
void Deque<DequeT>::push_element_back(DequeT value)
{
    if (RearPtr == nullptr || RearPtr == &blockmap[MapSize - 1][BLOCK_SIZE - 1]) // If the RearPtr is at the back of the block
    {
        if (MapSize >= capacity) // If the map is full
        {
            MapResize(); // Resize the map to double the capacity
        }
        NewBlockRear(); // Create a new block at the rear
        RearPtr = &blockmap[MapSize - 1][0]; // Set the RearPtr to the first element in the new block
    }
    *RearPtr = value; // Set the value of the RearPtr to the value passed in
    BlockElementCounter++; // Increment the number of elements in the blocks
    RearPtr++; // Move the RearPtr to the right
}



template <typename DequeT>
void Deque<DequeT>::NewBlockFront()
{
  if (blockmap == nullptr) // If the map is empty
    {
      blockmap = new DequeT *[capacity]; // Create a new map of pointers to the blocks
    }
  if (MapSize >= capacity) // If the map is full
    {
      MapResize(); // Resize the map to double the capacity
    }
  else
    {
      MapResize();
      blockmap[0] = new DequeT[BLOCK_SIZE]; //adds a new block to the start of the map.
    }
  MapSize++; // Increment the MapSize of the map
}

template <typename DequeT>
void Deque<DequeT>::MoveFrontPtrLeft()
{
    if (blockmap == nullptr) // If the map is empty
    {
        std::cout << "Blockmap is empty" << std::endl;
        return;
    }
    if (FrontPtr == blockmap[0][0])
    {
        NewBlockFront();
        FrontPtr--;
        return;
    }
    else
    {
        FrontPtr--;
        return;
    }
}

template <typename DequeT>
void Deque<DequeT>::MapResize()
{
    DequeT **temp = new DequeT *[capacity * 2]; // Create a new map of pointers to the blocks
    for (int i = 0; i < MapSize; i++)
    {
        temp[i + 1] = blockmap[i]; // Copy the pointers from the old map to the new map
    }
    delete[] blockmap; // Delete the old map
    blockmap = temp;   // Set the old map to the new map
    capacity *= 2;     // Double the capacity
}

template <typename DequeT>
void Deque<DequeT>::get_front()
{
    std::cout << *FrontPtr << std::endl;
}

template <typename DequeT>
DequeT &Deque<DequeT>::operator[](DequeT index) // Overloaded operator[] to access elements in the deque
{
    return blockmap[index];
}

template <typename DequeT>
void Deque<DequeT>::printBlockMap()
{
    for (int i = 0; i < MapSize; i++)
    {
        std::cout << "Blockmap[" << i << "] = " << blockmap[i] << " | and the values are: ";
        for (int j = 0; j < BLOCK_SIZE; j++)
        {
            std::cout << blockmap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
