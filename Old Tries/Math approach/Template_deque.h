/**
 * @file Template_deque.h
 * @author Jimmy Hart
 * @date 2024-04-26
 * @brief Deque Class
 * 
 * This is a custom class of the Deque from the std::deque library.
 */

#ifndef DEQUE_Bonus
#define DEQUE_Bonus
#include <iostream>


template <typename DequeT>
class Deque
{
private:
  DequeT **blockmap;   // Pointer to the map of pointers to the blocks
  int First_Block; // First block of the blockmap
  int First_Element; // First element of the blockmap 
  int capacity;       // Max capacity of the blockmap
  int size; // total amount of elements in the blockmap
  int MapSize; // Size of the blockmap
  int MapCapacity; // Capacity of the blockmap
  const static int BLOCK_SIZE = 5; // Size of each block in the arrays. This is a constant value that will never change for simplicity.
  

  int FrontCol; // Used to track the front column
  int RearCol; // Used to track the rear column
  

/**
 * void MapResize() : This resizes the blockmap whenever MapSize >= capacity
 *
 * @pre blockmap must be allocated and initilized
 * @return void 
 * @post The blockmap has been resized and the capacity has been increased.
 * 
 */
  void MapResize(); 


public:

/**
 * Standard Constructor
 *
 * @pre 
 * @post All values and pointers have been allocated, initalized and assigned.
 * 
 */
  Deque();

/**
 * Standard Destructor
 *
 * @pre 
 * @post All values and pointers in the class have been deleted/set to zero and set to null.
 * 
 */
  ~Deque();

/**
 * void push_element_front(DequeT value) : This puts a new value to the blockmap at the front, which is based on where frontptr is pointing; When this function is called, frontptr is moved to the left once by incrementation, then the value is inserted into the appopriate spot.
 *
 * @param DequeT value The value we are inserting
 * @pre blockmap must be existing with blocks already existing
 * @return void 
 * @post The frontptr has been moved and the value has been inserted.
 * 
 */
  void push_element_front(DequeT value);

/**
 * void push_element_back(DequeT value) : This puts a new value to the blockmap at the Rear, which is based on where RearPtr is pointer; When this function is called, RearPtr is moved to the right by the function "void MoveRearPtrRight()" and then inserts the value to the appropriate spot.
 *
 * @param DequeT value The value we are inserting
 * @pre blockmap must be existing with blocks already existing
 * @return void 
 * @post The RearPtr has been moved and the value has been inserted
 * 
 */
  void push_element_back(DequeT value);

/**
 * void pop_front() : pops the front block of the blockmap and moves the FrontPtr to the next block of the blockmap.
 *
 * @pre Must have Elements already inserted.
 * @return void 
 * @post The Front block of the blockmap has been popped
 * 
 */
  void pop_front();

/**
 * void pop_back() : pops the rear block of the blockmap and moves the RearPtr to the previous block of teh blockmap.
 *
 * @pre Must have Elements already inserted.
 * @return 
 * @post The Rear block of the blockmap has been popped
 * 
 */
  void pop_back();

/**
 * void get_front() : prints the front element of the blockmap using the FrontPtr
 *
 * @pre Must have Elements already inserted
 * @return void 
 * @post The FrontPtr gets de-refereneced and printed to the terminal.
 * 
 */
  void get_front(); 

/**
 * void get_back() : prints the tail element of the blockmap using the RearPtr
 *
 * @pre Must have Elements already inserted.
 * @return void 
 * @post The RearPtr gets de-refereneced and printed to the terminal.
 * 
 */
  void get_back(); 

/**
 * bool empty() : Checks if the deque is empty or not by using the Blockelementcounter as a way of checking
 *
 * @pre 
 * @return bool If true: Then it is empty | If false: Then it is not empty.
 * @post We return the boolean value
 * 
 */
  bool empty();

/**
 * int get_capacity() : Returns the capacity of the blockmap
 *
 * @pre 
 * @return int capacity
 * @post capacity has been returned
 * 
 */
  int get_capacity(); 

/**
 * int get_MapSize() : Returns of size of the blockmap
 *
 * @pre 
 * @return int MapSize
 * @post MapSize has been returned
 * 
 */
  int get_MapSize();
  DequeT &operator[](DequeT index);
  void NewDataBlock();
  void print();

  // DEBUGGER SECTION:
  void printBlockMap();
};


template <typename DequeT>
Deque<DequeT>::Deque()
{
  MapCapacity = BLOCK_SIZE;
  capacity = BLOCK_SIZE;
  size = 0;
  MapSize = 5;
  First_Element = 2;
  First_Block = 1;
  FrontCol = 2;
  RearCol = 2;


  blockmap = new DequeT*[BLOCK_SIZE];
  for(int i = 0; i < BLOCK_SIZE; i++)
    {
      blockmap[i] = new DequeT[BLOCK_SIZE];
    }

}


template <typename DequeT>
Deque<DequeT>::~Deque()
{
  for(int i = 0; i < MapCapacity; i++)
    {
      delete[] blockmap[i];
    }
  delete[] blockmap;
  blockmap = 0;
  capacity = 0;
  MapCapacity = 0;
  size = 0;
  MapSize = 0;
  First_Element = 0;
}

template <typename DequeT>
DequeT &Deque<DequeT>::operator[](DequeT index)
{ 
  if(index >= size)
  {
    std::cout << "ACCESS ERROR: Index out of bounds" << std::endl;
  }
  
  int row = First_Block + ((FrontCol + index) / BLOCK_SIZE);
  int col = (FrontCol + index) % BLOCK_SIZE;
  std::cout << "Row: " << row << " Col: " << col << std::endl;
  return blockmap[row][col];
}

template <typename DequeT>
void Deque<DequeT>::push_element_front(DequeT value)
{
  if(FrontCol <= 0)
    {
      FrontCol = BLOCK_SIZE; 
      MapResize();
    }
  FrontCol--;
  RearCol++;
  int row = First_Block + (FrontCol / BLOCK_SIZE);
  int col = FrontCol % BLOCK_SIZE;
  std::cout << "PUSH FRONT: Row: " << row << " FrontCol: " << FrontCol << std::endl;
  blockmap[row][col] = value;
  size++;
}


//TODO: This Push_Element_Back function will need to be tweaked.
template <typename DequeT>
void Deque<DequeT>::push_element_back(DequeT value)
{
  int row = First_Block + (RearCol / BLOCK_SIZE);
  int col = RearCol % BLOCK_SIZE;
  
  if(RearCol >= BLOCK_SIZE)
    {
      RearCol = 0; 
      //row++;
      col = RearCol % BLOCK_SIZE; // Update col after resetting RearCol
    }
  
  if(row >= MapCapacity)
    {
      MapResize();
      row = First_Block + (RearCol / BLOCK_SIZE);
      col = RearCol % BLOCK_SIZE;
    }
  
  blockmap[row][col] = value;
  RearCol++;
  size++;
  
  std::cout << "PUSH BACK: Row: " << row << " RearCol: " << RearCol << std::endl;
}

template <typename DequeT>
void Deque<DequeT>::MapResize()
{
  std::cout << std::endl;
  std::cout << "RESIZE MAPCAPACITY: " << MapCapacity << std::endl;
  DequeT **temp = new DequeT*[MapCapacity + 2];
  temp[0] = new DequeT[BLOCK_SIZE];
  for(int i = 0; i < MapCapacity + 1; i++)
    {
      temp[i + 1] = blockmap[i];
    }
  
  temp[MapCapacity + 1] = new DequeT[BLOCK_SIZE];
  delete[] blockmap;
  blockmap = temp;
  MapCapacity += 2;
  MapSize += 2;
  std::cout << "RESIZE AFTER: " << MapCapacity << std::endl;
  std::cout << std::endl;
}

#endif
