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
  DequeT *RearPtr;     // points to the last element in the deque. This allows us to do manipulation of the arrays over the entire blockmap. It will only go from the last half of the blockmap.
  DequeT *FrontPtr;    //points to the last element in the deque. This allows us to do manipulation of the arrays over the entire blockmap. It will only go from the first half of the blockmap.
  int capacity;
  int BlockElementCounter; // Counter for the number of elements in all the blocks.
  int MapSize;
  const static int BLOCK_SIZE = 5; // Size of each block in the arrays. This is a constant value that will never change for simplicity.

/**
 * void MapResize() : This resizes the blockmap whenever MapSize >= capacity
 *
 * @pre blockmap must be allocated and initilized
 * @return void 
 * @post The blockmap has been resized and the capacity has been increased.
 * 
 */
  void MapResize(); 

/**
 * void MapReSizeRight() : This function's main purpose is to resize the blockmap whenever the RearPointer reaches its end. It can be called any other time, but should not be used for anything else. When it does, we have space for the tail-end of the blockmap.
 *
 * @pre The blockmap has run out of space to its tail end.
 * @return void 
 * @post The blockmap has been resized with the tail end having extra space 
 * 
 */
  void MapResizeRight(); 

/**
 * void MapResizeleft() : This function's main purpose is to resize the blockmap whenver the FrontPtr reachs its end. It can be called any other time, but should not be used for anything else. When it does, it will resize blockmap to from the front and moves all the pointers of the blockmap to the frontmost area.
 *
 * @pre The blockmap has run of space to its front end.
 * @return void 
 * @post The blockmap has been resized with the front end having given more space and the capacity increased.
 * 
 */
  void MapResizeLeft();

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
  for(int i = 0; i < capacity; i++)
    {
      blockmap[i] = nullptr;
      delete blockmap[i];
    }
  delete[] blockmap;
  RearPtr = nullptr;
  FrontPtr = nullptr;
}


template <typename DequeT>
void Deque<DequeT>::get_back()
{
  if(BlockElementCounter > 0)
    {
      std::cout << "Back: " << *RearPtr << std::endl;
    }
  else
    {
      std::cout << "GET ERROR: There are no elements in the blockmap!" << std::endl;
    }
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
      std::cout << "blockmap is not empty" << std::endl;
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

template <typename DequeT>
void Deque<DequeT>::print()
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
      //std::cout << "Blockmap[" << i << "] = " << &blockmap[i] << " | and the values are: ";
      for (int j = 0; j < BLOCK_SIZE; j++)
        {
	  std::cout << blockmap[i][j] << " ";
        }
      std::cout << std::endl;
    }
}

#endif
