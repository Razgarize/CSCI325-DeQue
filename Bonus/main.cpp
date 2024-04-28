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
#include "Template_deque.h"

using namespace std;

int main() {
  Deque<int> Dint;
  int Num = 2;

  Deque<float> Dfloat;
  float FourDec = 0.2;

  Deque<double> Ddouble;
  double EightDec = 0.00005;

  Deque<char> Dchar;
  char Symbol = 33;

  cout<<"==============Deque-Testing=============="<<endl;
  cout<<"Deque empty check 1: "<<endl;
  cout<<"int: ";
  if (Dint.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"float: ";
  if (Dfloat.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"double: ";
  if (Ddouble.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Ddouble.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"char: ";
  if (Dchar.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dchar.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"========================================"<<endl;
  cout<<"Checking Deque Capacity and Block Total:"<<endl;
  cout<<"Integer Capacity: "<<Dint.get_capacity()<<endl;
  cout<<"Integer Block Amount: "<<Dint.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float Capacity: "<<Dfloat.get_capacity()<<endl;
  cout<<"Float Block Amount: "<<Dfloat.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double Capacity: "<<Ddouble.get_capacity()<<endl;
  cout<<"Double Block Amount: "<<Ddouble.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character Capacity: "<<Dchar.get_capacity()<<endl;
  cout<<"Character Block Amount: "<<Dchar.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"1000 pushes to the front"<<endl;
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
  cout<<"========================================"<<endl;
  cout<<"Integer deque: "<<endl;
  Dint.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float deque: "<<endl;
  Dfloat.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double deque: "<<endl;
  Ddouble.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character deque: "<<endl;
  Dchar.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  //second capacity/block check
  cout<<"Checking Deque Capacity and Block Total:"<<endl;
  cout<<"Integer Capacity: "<<Dint.get_capacity()<<endl;
  cout<<"Integer Block Amount: "<<Dint.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float Capacity: "<<Dfloat.get_capacity()<<endl;
  cout<<"Float Block Amount: "<<Dfloat.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double Capacity: "<<Ddouble.get_capacity()<<endl;
  cout<<"Double Block Amount: "<<Ddouble.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character Capacity: "<<Dchar.get_capacity()<<endl;
  cout<<"Character Block Amount: "<<Dchar.get_MapSize()<<endl;
  cout<<"========================================"<<endl;
  cout<<"Deque empty check 2: "<<endl;
  cout<<"int: ";
  if (Dint.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"float: ";
  if (Dfloat.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dfloat.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"double: ";
  if (Ddouble.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Ddouble.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"char: ";
  if (Dchar.empty() == true){
    cout<<"This Deque is empty"<<endl;
  }
  else if (Dchar.empty() == false){
    cout<<"This Deque is not empty"<<endl;
  }
  cout<<"========================================"<<endl;
  cout<<"Popping half of the contents from the front"<<endl;
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
  cout<<"Printing the new deque:"<<endl;
  cout<<"========================================"<<endl;
  cout<<"Integar deque: "<<endl;
  Dint.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float deque: "<<endl;
  Dfloat.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double deque: "<<endl;
  Ddouble.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character deque: "<<endl;
  Dchar.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Resetting deque"<<endl;
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
  cout<<"1000 pushes to the back..."<<endl;
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
  cout<<"Printing the new deque:"<<endl;
  cout<<"========================================"<<endl;
  cout<<"Integar deque: "<<endl;
  Dint.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float deque: "<<endl;
  Dfloat.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double deque: "<<endl;
  Ddouble.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character deque: "<<endl;
  Dchar.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Popping half the contents from the back..."<<endl;
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
  cout<<"Printing the new deque:"<<endl;
  cout<<"========================================"<<endl;
  cout<<"Integar deque: "<<endl;
  Dint.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Float deque: "<<endl;
  Dfloat.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Double deque: "<<endl;
  Ddouble.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Character deque: "<<endl;
  Dchar.print();
  cout<<endl;
  cout<<"========================================"<<endl;
  cout<<"Resetting Deque..."<<endl;
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
  cout<<"Regenerating deques..."<<endl;
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
  cout<<"========================================"<<endl;
  cout<<"Testing Integer Random Accesss"<<endl;
  for (int i = 0; i < 100; i++){
    Dint[i] = Num;
    Num + 2;
    cout<<"Output Dint["<<i<<"]: "<<Dint[i]<<endl;
  }
  cout<<"========================================"<<endl;
  for (int i = 0; i < 100; i++){
    Dfloat[i] = FourDec;
    FourDec += FourDec;
    cout<<"Output Dfloat["<<i<<"]: "<<Dfloat[i]<<endl;
  }
  cout<<"========================================"<<endl;
  for (int i = 0; i < 100; i++){
    Ddouble[i] = EightDec;
    EightDec += EightDec;
    cout<<"Output Ddouble["<<i<<"]: "<<Ddouble[i]<<endl;
  }
  cout<<"========================================"<<endl;
  for (int i = 0; i < 93; i++){
    Dchar[i] = Symbol;
    Symbol += 1;
    cout<<"Output Dchar["<<i<<"]: "<<Dchar[i]<<endl;
  }
  cout<<"========================================"<<endl;
  cout<<"Checking the first item in The Deque:"<<endl;
  cout<<"Integer:"<<endl;
  Dint.get_front();
  cout<<"Float:"<<endl;
  Dfloat.get_front();
  cout<<"Double:"<<endl;
  Ddouble.get_front();
  cout<<"Character:"<<endl;
  Dchar.get_front();
  cout<<"========================================"<<endl;
  cout<<"Checking the last item in The Deque:"<<endl;
  cout<<"Integer:"<<endl;
  Dint.get_back();
  cout<<"Float:"<<endl;
  Dfloat.get_back();
  cout<<"Double:"<<endl;
  Ddouble.get_back();
  cout<<"Character:"<<endl;
  Dchar.get_back();
  cout<<"========================================"<<endl;
  cout<<"Deque tests concluded"<<endl;

    return 0
      }
