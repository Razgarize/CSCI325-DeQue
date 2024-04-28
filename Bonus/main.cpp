/**
 * @file main_bonus.cpp
 * @author Daemon Bytes
 * @date 2024-04-26
 * @brief The driver and menu for the Deque template
 *
 *
 */

#include <iostream>
#include <string>
#include <fstream> 
#include "Template_deque.h"

using namespace std;
ofstream out("results.txt");

int main() {
  Deque<int> Dint;
  int Num = 2;

  Deque<float> Dfloat;
  float FourDec = 0.2;

  Deque<double> Ddouble;
  double EightDec = 0.00005;

  Deque<char> Dchar;
  char Symbol = 33;

  out<<"==============Deque-Testing=============="<<endl;
  out<<"Deque empty check 1: "<<endl;
  out<<"int: ";
  if (Dint.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  cout<<"float: ";
  if (Dfloat.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"double: ";
  if (Ddouble.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Ddouble.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"char: ";
  if (Dchar.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dchar.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"========================================"<<endl;
  out<<"Checking Deque Capacity and Block Total:"<<endl;
  out<<"Integer Capacity: "<<Dint.get_capacity()<<endl;
  out<<"Integer Block Amount: "<<Dint.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Float Capacity: "<<Dfloat.get_capacity()<<endl;
  out<<"Float Block Amount: "<<Dfloat.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Double Capacity: "<<Ddouble.get_capacity()<<endl;
  out<<"Double Block Amount: "<<Ddouble.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Character Capacity: "<<Dchar.get_capacity()<<endl;
  out<<"Character Block Amount: "<<Dchar.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"1000 pushes to the front"<<endl;
  for(int i = 0; i < 1000; i++){
    Dint.push_element_front(i);
    }
  for(float i = 0; i < 10; i+= 0.01){
    Dfloat.push_element_front(i);
      }
  for(double i = 0.001; i < 1; i+= 0.001){
    Ddouble.push_element_front(i);
      }
  for(char i = 33; i < 127; i++){
    Dchar.push_element_front(i);
      }
  out<<"========================================"<<endl;
  out<<"Integer deque: "<<endl;
  Dint.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Float deque: "<<endl;
  Dfloat.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Double deque: "<<endl;
  Ddouble.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Character deque: "<<endl;
  Dchar.print();
  out<<endl;
  out<<"========================================"<<endl;
  //second capacity/block check
  out<<"Checking Deque Capacity and Block Total:"<<endl;
  out<<"Integer Capacity: "<<Dint.get_capacity()<<endl;
  out<<"Integer Block Amount: "<<Dint.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Float Capacity: "<<Dfloat.get_capacity()<<endl;
  out<<"Float Block Amount: "<<Dfloat.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Double Capacity: "<<Ddouble.get_capacity()<<endl;
  out<<"Double Block Amount: "<<Ddouble.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Character Capacity: "<<Dchar.get_capacity()<<endl;
  out<<"Character Block Amount: "<<Dchar.get_MapSize()<<endl;
  out<<"========================================"<<endl;
  out<<"Deque empty check 2: "<<endl;
  out<<"int: ";
  if (Dint.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"float: ";
  if (Dfloat.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"double: ";
  if (Ddouble.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Ddouble.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"char: ";
  if (Dchar.empty() == true){
    out<<"This Deque is empty"<<endl;
  }
  else if (Dchar.empty() == false){
    out<<"This Deque is not empty"<<endl;
  }
  out<<"========================================"<<endl;
  out<<"Popping half of the contents from the front"<<endl; 
  for (int i = 0; i < Dint.get_MapSize()/2; i++){
    Dint.pop_front();
  }
  for (int i = 0; i < Dfloat.get_MapSize()/2; i++){
    Dfloat.pop_front();
  }
  for (int i = 0; i < Ddouble.get_MapSize()/2; i++){
    Ddouble.pop_front();
  }
  for (int i = 0; i < Dchar.get_MapSize()/2; i++){
    Dchar.pop_front();
  }
  out<<"Printing the new deque:"<<endl; 
  out<<"========================================"<<endl;
  out<<"Integar deque: "<<endl;
  Dint.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Float deque: "<<endl;
  Dfloat.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Double deque: "<<endl;
  Ddouble.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Character deque: "<<endl;
  Dchar.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Resetting deque"<<endl;
  //removes the other half of the deque
  for (int i = 0; i < Dint.get_MapSize()/2; i++){
    Dint.pop_front();
  }
  for (int i = 0; i < Dfloat.get_MapSize()/2; i++){
    Dfloat.pop_front();
  }
  for (int i = 0; i < Ddouble.get_MapSize()/2; i++){
    Ddouble.pop_front();
  }
  for (int i = 0; i < Dchar.get_MapSize()/2; i++){
    Dchar.pop_front();
  }
  out<<"1000 pushes to the back..."<<endl;
  for(int i = 0; i < 1000; i++){
    Dint.push_element_back(i);
      }
  for(float i = 0; i < 10; i+= 0.01){
    Dfloat.push_element_back(i);
      }
  for(double i = 0.001; i < 1; i+= 0.001){
    Ddouble.push_element_back(i);
      }
  for(char i = 33; i < 127; i++){
    Dchar.push_element_back(i);
      }
  out<<"Printing the new deque:"<<endl;
  out<<"========================================"<<endl;
  out<<"Integar deque: "<<endl;
  Dint.print();
  out<<cout<<endl;
  out<<"========================================"<<endl;
  out<<"Float deque: "<<endl;
  Dfloat.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Double deque: "<<endl;
  Ddouble.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Character deque: "<<endl;
  Dchar.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Popping half the contents from the back..."<<endl;
  for (int i = 0; i < Dint.get_MapSize()/2; i++){
    Dint.pop_back();
  }
  for (int i = 0; i < Dfloat.get_MapSize()/2; i++){
    Dfloat.pop_back();
  }
  for (int i = 0; i < Ddouble.get_MapSize()/2; i++){
    Ddouble.pop_back();
  }
  for (int i = 0; i < Dchar.get_MapSize()/2; i++){
    Dchar.pop_back();
  }
  out<<"Printing the new deque:"<<endl;
  out<<"========================================"<<endl;
  out<<"Integar deque: "<<endl;
  Dint.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Float deque: "<<endl;
  Dfloat.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Double deque: "<<endl;
  Ddouble.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Character deque: "<<endl;
  Dchar.print();
  out<<endl;
  out<<"========================================"<<endl;
  out<<"Resetting Deque..."<<endl;
  //cleans the deque up
  for (int i = 0; i < Dint.get_MapSize()/2; i++){
    Dint.pop_back();
  }
  for (int i = 0; i < Dfloat.get_MapSize()/2; i++){
    Dfloat.pop_back();
  }
  for (int i = 0; i < Ddouble.get_MapSize()/2; i++){
    Ddouble.pop_back();
  }
  for (int i = 0; i < Dchar.get_MapSize()/2; i++){
    Dchar.pop_back();
  }
  out<<"Regenerating deques..."<<endl;
  //generates new deque
  for(int i = 0; i < 1000; i++){
    Dint.push_element_front(i);
      }
  for(float i = 0; i < 10; i+= 0.01){
    Dfloat.push_element_front(i);
      }
  for(double i = 0.001; i < 1; i+= 0.001){
    Ddouble.push_element_front(i);
      }
  for(char i = 33; i < 127; i++){
    Dchar.push_element_front(i);
      }
  out<<"========================================"<<endl;
  out<<"Testing Integer Random Accesss"<<endl;
  for (int i = 0; i < 100; i++){
    Dint[i] = Num;
    Num + 2;
    out<<"Output Dint["<<i<<"]: "<<Dint[i]<<endl;
  }
  out<<"========================================"<<endl;
  for (int i = 0; i < 100; i++){
    Dfloat[i] = FourDec;
      FourDec += FourDec;
      out<<"Output Dfloat["<<i<<"]: "<<Dfloat[i]<<endl;
    }
  out<<"========================================"<<endl;
  for (int i = 0; i < 100; i++){
    Ddouble[i] = EightDec;
    EightDec += EightDec;
    out<<"Output Ddouble["<<i<<"]: "<<Ddouble[i]<<endl;
  }
  out<<"========================================"<<endl;
  for (int i = 0; i < 93; i++){
    Dchar[i] = Symbol;
    Symbol += 1;
    out<<"Output Dchar["<<i<<"]: "<<Dchar[i]<<endl;
  }
  out<<"========================================"<<endl;
  out<<"Checking the first item in The Deque:"<<endl;
  out<<"Integer:"<<endl;
  Dint.get_front();
  out<<"Float:"<<endl;
  Dfloat.get_front();
  out<<"Double:"<<endl;
  Ddouble.get_front();
  out<<"Character:"<<endl;
  Dchar.get_front();
  out<<"========================================"<<endl;
  out<<"Checking the last item in The Deque:"<<endl;
  out<<"Integer:"<<endl;
  Dint.get_back();
  cout<<"Float:"<<endl;
  Dfloat.get_back();
  out<<"Double:"<<endl;
  Ddouble.get_back();
  out<<"Character:"<<endl;
  Dchar.get_back();
  out<<"========================================"<<endl;
  out<<"Deque tests concluded"<<endl;

  cout<<"If you are seeing this, results.txt should be created and now readable! the test results are there" 
  return 0
}
