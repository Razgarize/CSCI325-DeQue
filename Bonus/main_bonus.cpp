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
  int menu;
  string input;
  
  //incase these are needed
  Deque<int> Dint;
  int Num = 2;
  
  Deque<float> Dfloat;
  float FourDec = 0.02;

  Deque<double> Ddouble;
  doubles EightDec = 0.00002;

  Deque<char> Dchar; 
  char Symbol = 33;
  //======================
  
  cout<<"==========DEQUE-TESTING=========="<<endl;
  cout<<"Welcome to the Testing Terminal! Type in the number to the respective test you wish to run:"<<endl;
while (menu != 15){
  cout<<"========================================"<<endl;
  cout<<"1 To check if the Deque is empty"<<endl;
  cout<<"2 To Push 100 values to the front"<<endl;
  cout<<"3 To Push 1000 values to the front"<<endl;
  cout<<"4 To Push 100 values to the back"<<endl;
  cout<<"5 To Push 1000 values to the back"<<endl;
  cout<<"6 To Pop 100 values from the front"<<endl;
  cout<<"7 To Pop 1000 values from the front"<<endl;
  cout<<"8 To Pop 100 values from the back"<<endl;
  cout<<"9 To Pop 1000 values from the back"<<endl; 
  cout<<"10 To Access a Random Item in the Deque"<<endl;
  cout<<"11 To See the Capacity of The Deque and block amount"<<endl;
  cout<<"12 To Print the Contents of The Deque"<<endl;
  cout<<"13 To See the First item in the Deque"<<endl;
  cout<<"14 To see the Last item in the Deque"<<endl; 
  cout<<"15 To exit the program"<<endl;
  cout<<"========================================"<<endl;
  
  cout << "Please enter your selection: ";
  cin>>menu;
  cout<<"========================================"<<endl;

  if(cin.fail()) //Logic Guard, protects the user from enter non-numerical values.
    {
      cin.clear();
      cin.ignore(10000, '\n');
      menu = 0;
      cout << "Please enter valid options. Numerical characters only!" << endl;
    }

  if (menu == 1){
    //checks if the deque is empty
    cout<<"Please select a data type(int, float, double, char): "<<endl;

    while(input != "int" or input != "float" or input != "double" or input != "char"){
      cin>>input;
      if(input == "int"){
	if (Dint.empty() == true){
	  cout<<"The Deque is empty!"<<endl;
	}
	else{
	  cout<<"The Deque is not empty!"<<endl;
	}
	
      }
      if else(input == "float"){
	  if (Dfloat.empty() == true){
	    cout<<"The Deque is empty!"<<endl;
	  }
	  else{
	    cout<<"The Deque is not empty!"<<endl;
	  }
	  
	}
      if else(input == "double"){
	  if (Ddouble.empty() == true){
	    cout<<"The Deque is empty!"<<endl;
	  }
	  else{
	    cout<<"The Deque is not empty!"<<endl;
	  }
	}
      if else(input == "char"){
	  if (Dchar.empty() == true){
	    cout<<"The Deque is empty!"<<endl;
	  }
	  else{
	    cout<<"The Deque is not empty!"<<endl;
	  }
	  
	}
    }
    
  if (menu == 2){
    //pushes 100 values to the front
    cout<<"Please select a data type(int, float, double, char): "<<endl;
    cin>>input;

    if (input == "int"){
      for (int i = 0; i < 100; i++){
	Dint.push_element_front(i); 
      }
    }
    else if (input == "float"){
      for (float i = 1; i < 10; i+=0.01){
	Dfloat.push_element_front(i);
      }
    }
    else if (input == "double"){
      for (double i = 0.0001; i < 1; i+=0.0001){
	Ddouble.push_element_front(i);
      }
    }
    else if (input == "char"){
      for (char i = 33; i < 127; i++){
	Dchar.push_element_front(i); 
      }
    }
  }
  if (menu == 3){
    //pushes 1000 values to the front
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.push_element_front(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.push_element_front(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.push_element_front(i);
   }
 }
 else if (input == "char"){
   Dchar.push_element_front(i);
 }
  }
  
  
  if (menu == 4){
    //pushes 100 values to the back
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.push_element_back(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; I += 0.01){
     Dfloat.push_element_back(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; I += 0.0001){
     Ddouble.push_element_back(i);
   }
 }
 else if (input == "char"){
   Dchar.push_element_back(i);
 }
  }
  

 if (menu == 5){
    //pushes 1000 values to the back
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.push_element_back(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.push_element_back(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.push_element_back(i);
   }
 }
 else if (input == "char"){
   for (char i = 33; i < 127; i++){
     Dchar.push_element_back(i);
   }
 }
 
  if (menu == 6){
    //pops 100 values from the front
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.pop_front(i); 
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.pop_front(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.pop_front(i);
   }
 }
 else if (input == "char"){
   for (char i = 33; i < 127; i++){
     Dchar.pop_front(i);
   }
 }
  }
  
  if (menu == 7){
    //pops 1000 values from the front
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.pop_front(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.pop_front(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.pop_front(i);
   }
 }
 else if (input == "char"){
   for (char i = 33; i < 127; i++){
     Dchar.pop_front(i);
   }
 }
  }
  
 
  if (menu == 8){
    //pops 100 values from the back
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.pop_back(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.pop_back(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.pop_back(i);
   }
 }
 else if (input == "char"){
   for (char i = 33; i < 127; i++){
     Dchar.pop_back(i);
   }
   
 }
  }
 
  if (menu == 9){
    //pops 1000 values from the back
cout<<"Please select a data type(int, float,double,char):"<<endl; 
cin>>input;

 if (input == "int"){
   for (int i = 0; i < 100; i++){
     Dint.pop_back(i);
   }
 }
 else if (input == "float"){
   for (float i = 0; i < 1; i += 0.01){
     Dfloat.pop_back(i);
   }
 }
 else if (input == "double"){
   for (double i = 0.0001; i < 1; i += 0.0001){
     Ddouble.pop_back(i);
   }
 }
 else if (input == "char"){
   for (char i = 33; i < 127; i++){
     Dchar.pop_back(i);
   }
 }
  }
  
  if (menu == 10){
    //Random Access test
    cout<<"Please select a data type(int, float,double,char):"<<endl;
    cin>>input; 

    if (input == "int"){
      for (i = 0; i < 100; i++){
	cout<<"Placing "<<Num<<" into position "<<i<<endl;
	Dint[i] = Num;
	Num *= Num;
	cout<<"Output Dint["<<i<<"]: "<<Dint[i];
      }
    }
    if (input == "float"){
      for (i = 0; i < 100; i++){
	cout<<"Placing "<<FourDec<<" into position "<<i<<endl;
	Dfloat[i] = FourDec;
	FourDec += FourDec;
	cout<<"Output Dfloat["<<i<<"]: "<<Dfloat[i];
      }
    }
    if (input == "double"){
      for (i = 0; i < 100; i++){
	cout<<"Placing "<<EightDec<<" into position "<<i<<endl;
	Ddouble[i] = EightDec;
	EightDec += EightDec;
	cout<<"Output Ddouble["<<i<<"]: "<<Ddouble[i];
      }
    }
    if (input == "char"){
      for (i = 0; i < 93; i++){
	cout<<"Placing "<<Symbol<<" into position "<<i<<endl;
	Dchar[i] = Symbol;
	Symbol += 1;
	cout<<"Output Dchar["<<i<<"]: "<<Dchar[i];
      }
    }
  }
  if (menu == 11){
    //Get the capacity of the deque on display and how many blocks are in it
    cout<<"Please select a data type(int, float,double,char):"<<endl;
    cin>>input;

    if (input == "int"){
      cout<<"Capacity: "<<Dint.get_capacity()<<endl;
      cout<<"Block Amount: "<<Dint.get_MapSize()<<endl;
    }
    if (input == "float"){
      cout<<"Capacity: "<<Dfloat.get_capacity()<<endl;
      cout<<"Block Amount: "<<Dfloat.get_MapSize()<<endl;
    }
    if (input == "double"){
      cout<<"Capacity: "<<Ddouble.get_capacity()<<endl;
      cout<<"Block Amount: "<<Ddouble.get_MapSize()<<endl;
    }
    if (input == "char"){
      cout<<"Capacity: "<<Dchar.get_capacity()<<endl;
      cout<<"Block Amount: "<<Dchar.get_MapSize()<<endl;
    }
  }
  if (menu == 12){
    //print
    cout<<"Please select a data type(int, float,double,char):"<<endl;
    cin>>input;

    if (input == "int"){
      Dint.print();
    }
    if (input == "float"){
      Dfloat.print();
    }
    if (input == "double"){
      Ddouble.print();
    }
    if (input == "char"){
      Dchar.print();
    }
  }
  if (menu == 13){
    //the first item
    cout<<"Please select a data type(int, float,double,char):"<<endl;
    cin>>input;

    if (input == "int"){
      Dint.get_front();
    }
    if (input == "float"){
      Dfloat.get_front();
    }
    if (input == "double"){
      Ddouble.get_front();
    }
    if (input == "char"){
      Dchar.get_front(); 
    }
    
  }
  if (menu == 14){
    //the last item
    cout<<"Please select a data type(int, float,double,char):"<<endl;
    cin>>input;

    if (input == "int"){
      Dint.get_back();
    }
    if (input == "float"){
      Dfloat.get_back();
    }
    if (input == "double"){
      Ddouble.get_back();
    }
    if (input == "char"){
      Dchar.get_back();
    }
  }
  else if (menu <= 0 or menu > 15) {
    cout<<"Invalid Option, Please try again!\n"<<endl;
  }
  
 }
 return 0;
}
