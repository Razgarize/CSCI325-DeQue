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
    int capacity;
    int BlockElementCounter; // Counter for the number of elements in all the blocks.
    int MapSize;
    const static int BLOCK_SIZE = 5; // Size of each block in the arrays. This is a constant value that will never change for simplicity.
    void MapResize();
    void MapResizeRight();
    void MapResizeLeft();

public:
    Deque();
    ~Deque();
    void push_element_front(DequeT value);
    void push_element_back(DequeT value);
    void pop_front();
    void pop_back();
    void get_front();
    void get_back();
    bool empty();
    int get_capacity();
    int get_MapSize();
    void MapResizeHelper();
    DequeT &operator[](DequeT index);
    void MoveRearPtrRight();
    void MoveFrontPtrLeft();
    void NewBlockFront();
    void NewBlockRear();
    void print();

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
    
}


template <typename DequeT>
Deque<DequeT>::~Deque() // Destructor
{
    delete[] blockmap;
}


template <typename DequeT>
void Deque<DequeT>::get_back()
{
    std::cout << "Back: " << *RearPtr << std::endl;
}

template <typename DequeT>
void Deque<DequeT>::pop_back()
{
  if(BlockElementCounter == 0)
    {
      std::cout << "POP BACK ERROR: There are no elements in the DeQue!" << std::endl;
      return;
    }
    else
    {
    for(int i = 0; i < BLOCK_SIZE; i++)
    {
      std::cout << "for loop: Pop Back: " << i << std::endl;
      if(RearPtr == &blockmap[MapSize - 1][0]) // If the RearPtr is at the end of the block (Our ultimate end goal).
      {
        //Once we get to the end of the block, we will delete the block and move the RearPtr to the last element of the now last block.
        delete[] blockmap[MapSize - 1]; // Delete the block
        MapSize--; // Decrement the MapSize
        RearPtr = &blockmap[MapSize - 1][BLOCK_SIZE - 1]; // Set the RearPtr to the last element in the new block
        BlockElementCounter--; // Decrement the number of elements in the blocks
        return; // Exit the function and end the loop
      }
      else
      {
        RearPtr--; // Move the RearPtr to the left
        BlockElementCounter--; // Decrement the number of elements in the blocks
      }
    }
}
    
}

template <typename DequeT>
void Deque<DequeT>::get_front()
{
    if(BlockElementCounter == 0)
    {
      std::cout << "GET FRONT ERROR: There are no elements in the DeQue!" << std::endl;
      return;
    }
    std::cout << "Front: " << *FrontPtr << std::endl;
}


template <typename DequeT>
void Deque<DequeT>::pop_front()
{
    for(int i = 0; i < BLOCK_SIZE; i++)
    {
      std::cout << "for loop: Pop Front: " << i << std::endl;
      if(FrontPtr == &blockmap[0][BLOCK_SIZE - 1]) // If the FrontPtr is at the beginning of the block (Our ultimate end goal).
      {
        //Once we get to the beginning of the block, we will delete the block and move the FrontPtr to the first element of the now first block.
        delete[] blockmap[0]; // Delete the block
        MapSize--; // Decrement the MapSize
        FrontPtr = &blockmap[0][0]; // Set the FrontPtr to the first element in the new block
        BlockElementCounter--; // Decrement the number of elements in the blocks
        return; // Exit the function and end the loop
      }
      else
      {
        FrontPtr++; // Move the FrontPtr to the right
        BlockElementCounter--; // Decrement the number of elements in the blocks
      }
    }
}


template <typename DequeT>
bool Deque<DequeT>::empty()
{
  if(BlockElementCounter <= 0)
    {
      return true;
    }
  else
    {
      return false;
    }
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
    for(int i = 0; i < BLOCK_SIZE; i++)
    {
        blockmap[MapSize][i] = 0;
    }
    MapSize++; // Increment the MapSize of the map
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
      for(int i = 0; i < BLOCK_SIZE; i++)
        {
            blockmap[0][i] = 0;
        }
        MapSize++; // Increment the MapSize of the map
    }
  
}

template <typename DequeT>
void Deque<DequeT>::push_element_front(DequeT value)
{
    if (FrontPtr == blockmap[0]) // If the FrontPtr is at the beginning of the block
    {
      //std::cout << "PUSH: FrontPtr is at the beginning of the block" << std::endl;
        NewBlockFront(); // Create a new block at the front
        FrontPtr = &blockmap[0][BLOCK_SIZE - 1]; // Set the FrontPtr to the last element in the new block
        *FrontPtr = value; // Set the value of the FrontPtr to the value passed in
        BlockElementCounter++; // Increment the number of elements in the blocks
    }
    else
    {
      //std::cout << "PUSH: FrontPtr is moving left" << std::endl;
        FrontPtr--; // Move the FrontPtr to the left
        *FrontPtr = value; // Set the value of the FrontPtr to the value passed in
        BlockElementCounter++; // Increment the number of elements in the blocks
    }
}

template <typename DequeT>
void Deque<DequeT>::push_element_back(DequeT value)
{
    if (RearPtr == nullptr or RearPtr == &blockmap[MapSize - 1][BLOCK_SIZE]) // If the RearPtr is at the back of the block
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
int Deque<DequeT>::get_capacity()
{
    return capacity;
}
template <typename DequeT>
int Deque<DequeT>::get_MapSize()
{
    return MapSize;
}

template <typename DequeT>
void Deque<DequeT>::MoveFrontPtrLeft()
{
    if (blockmap == nullptr) // If the map is empty
    {
      //std::cout << "Blockmap is empty" << std::endl;
        return;
    }
    if (FrontPtr == blockmap[0][0])
    {
      //std::cout << "FrontPtr is at the beginning of the block" << std::endl;
        NewBlockFront();
        FrontPtr--;
        return;
    }
    else
    {
      //std::cout << "FrontPtr is moving left" << std::endl;
        FrontPtr--;
        return;
    }
}

template <typename DequeT>
void Deque<DequeT>::MapResize()
{
    DequeT **temp = new DequeT *[capacity + 2]; // Create a new map of pointers to the blocks with new capacity
    for (int i = 0; i < MapSize; i++)
    {
        temp[i + 1] = blockmap[i]; // Copy the pointers from the old map to the new map
    }
    delete[] blockmap; // Delete the old map
    blockmap = temp;   // Set the old map to the new map
    capacity += 2;     // Increases the capacity by 2
}



//TODO: Implement the get_back() function
template <typename DequeT>
DequeT &Deque<DequeT>::operator[](DequeT index) // Overloaded operator[] to access elements in the deque
{
    if (index < 0 or index >= BlockElementCounter) // If the index is out of bounds
    {
        std::cout << "ACCESS ERROR: Index out of bounds" << std::endl; // DEBUGGER: Remove when finished
        return blockmap[0][0]; // Return the first element in the first block
    }
    int block = index / BLOCK_SIZE; // Calculate the block number'
    int blockIndex = index % BLOCK_SIZE; // Calculate the index in the block
    return blockmap[block][blockIndex]; // Return the element at the index
}

template <typename DequeT>
void Deque<DequeT>::printBlockMap()
{
  if(blockmap == nullptr)
    {
      std::cout << "PRINT ERROR: Blockmap is empty" << std::endl;
      return;
    }
    if(MapSize == 0)
    {
      std::cout << "PRINT ERROR: Blockmap is empty" << std::endl;
      return;
    }
    if(BlockElementCounter == 0)
    {
      std::cout << "PRINT ERROR: There are no inserted elements in the DeQue!" << std::endl;
      return;
    }
    for (int i = 0; i < MapSize; i++)
    {
        std::cout << "Blockmap[" << i << "] = " << &blockmap[i] << " | and the values are: ";
        for (int j = 0; j < BLOCK_SIZE; j++)
        {
            std::cout << blockmap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif