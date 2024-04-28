#ifndef DEQUE_BONUS
#define DEQUE_BONUS
#include <iostream>
#include <cmath>

template <typename DequeT>
class Deque
{
 private:
  DequeT **BlockMap;
  DequeT *DataBlock;
  const DequeT DataBlockCapacity = 5;
  int capacity;
  int size;
  int MapSize;
  DequeT FirstBlock;
  DequeT FirstElement;
 public:
  Deque();
  ~Deque();
  void push_front(DequeT element);
  void push_back();
  DequeT return_front();
  DequeT return_back();
  bool empty();
  int return_size();
  DequeT &operator[](DequeT index);


  //DEBUGGING:
  void print();

};

template <typename DequeT>
Deque<DequeT>::Deque()
{
  capacity = 10;
  size = 0;
  MapSize = 0;
  BlockMap = new DequeT *[capacity];

}

template <typename DequeT>
Deque<DequeT>::~Deque()
{
  delete BlockMap;
  capacity = 0;
  size = 0;

}


template <typename DequeT>
DequeT &Deque<DequeT>::operator[](DequeT index) // Overloaded operator[] to access elements in the deque
{
  DequeT row = FirstBlock + floor(FirstElement + index)/capacity;
  DequeT column = (FirstElement + index) % DataBlockCapacity;
  return BlockMap[row][column];
}

template <typename DequeT>
void Deque<DequeT>::push_front(DequeT element)
{
  if(size <= 0)
    {
      FirstElement = element;
      size++;
    }
  
  if(MapSize >= capacity)
    {
      temp = new DequeT *[capacity*2];
      for(Deque i = 0; i < capcity; i++)
	{
	  
  
}


template <typename DequeT>
void Deque<DequeT>::print()
{
  for(DequeT i = 0; i < 10; i++)
    {
  std::cout << BlockMap[i] << std::endl;
    }
}




#endif
