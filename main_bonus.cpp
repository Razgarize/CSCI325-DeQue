#include <iostream>
#include <string>
#include "Template_deque.h"

using namespace std;

int main() {
//   int menu;
//   string input;
//   //incase these are needed
//   int option1 = 0;
//   float option2 = 0;
//   double option3 = 0;
//   char option4 = 0;
//   //======================
  
//   cout<<"==========DEQUE-TESTING=========="<<endl;
//   cout<<"Welcome to the Testing Terminal! Type in the number to the respective test you wish to run:"<<endl;
// while (menu != 15){
//   cout<<"========================================"<<endl;
//   cout<<"1 To check if the Deque is empty"<<endl;
//   cout<<"2 To Push 100 values to the front"<<endl;
//   cout<<"3 To Push 1000 values to the front"<<endl;
//   cout<<"4 To Push 100 values to the back"<<endl;
//   cout<<"5 To Push 1000 values to the back"<<endl;
//   cout<<"6 To Pop 100 values from the front"<<endl;
//   cout<<"7 To Pop 1000 values from the front"<<endl;
//   cout<<"8 To Pop 100 values from the back"<<endl;
//   cout<<"9 To Pop 1000 values from the back"<<endl; 
//   cout<<"10 To Access a Random Item in the Deque"<<endl;
//   cout<<"11 To See the Size/Capacity of The Deque"<<endl;
//   cout<<"12 To Print the Contents of The Deque"<<endl;
//   cout<<"13 To See the First item in the Deque"<<endl;
//   cout<<"14 To see the Last item in the Deque"<<endl; 
//   cout<<"15 To exit the program"<<endl;
//   cout<<"========================================"<<endl;
  
//   cout << "Please enter your selection: ";
//   cin>>menu;
//   cout<<"========================================"<<endl;
//   if(cin.fail()) //Logic Guard, protects the user from enter non-numerical values.
//     {
//       cin.clear();
//       cin.ignore(10000, '\n');
//       menu = 0;
//       cout << "Please enter valid options. Numerical characters only!" << endl;
//     }

//   if (menu == 1){
//     if (d.empty() == true){
//       cout<<"The Deque is empty!"<<endl;
//     }
//     else if (d.empty() == false){
//       cout<<"The Deque is not empty!"<<endl;
//   }
//   if (menu == 2){
//     //pushes 100 values to the front
//     cout<<"Please select a data type(int, float, double, char): "<<endl;
//     cin>>input;

//     if (input == "int"){
//       for (i = 0; i < 100; i++){
	
//       }
//     }
//     else if (input == "float"){
//       for (i = 0; i < 100; i++){
	
//       }
//     }
//     else if (input == "double"){
//       for (i = 0.1; i < 10; i++){
	
//       }
//     }
//     else if (input == "char"){
      
//     }
//   }
//   if (menu == 3){
//     //pushes 1000 values to the front
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
//  else if (input == "char"){
   
//  }
//   }
//   if (menu == 4){
//     //pushes 100 values to the back
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
//  else if (input == "char"){
   
//  }   
//   }
//   if (menu == 5){
//     //pushes 1000 values to the back
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
// else if (input == "char"){

// }  
//   }
//   if (menu == 6){
//     //pops 100 values from the front
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
//  else if (input == "char"){
   
//  }   
//   }
//   if (menu == 7){
//     //pops 1000 values from the front
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
//  else if (input == "char"){
   
//  }
//   }
//   if (menu == 8){
//     //pops 100 values from the back
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){
//     Deque<input> d;
    
//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
// else if (input == "char"){

//  }
//   }
//   if (menu == 9){
//     //pops 1000 values from the back
// cout<<"Please select a data type(int, float,double,char):"<<endl; 
// cin>>input;

//  if (input == "int"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "float"){
//    for (i = 0; i < 100; i++){

//    }
//  }
//  else if (input == "double"){
//    for (i = 0.1; i < 10; i++){

//    }
//  }
//  else if (input == "char"){
   
//  }
//   }
//   if (menu == 10){
//     //Random Access test
//     cout<<"10"<<endl;
//   }
//   if (menu == 11){
//     //Get the size and capacity of the deque on display
//     cout<<"11"<<endl;
//   }
//   if (menu == 12){
//     //print
//     cout<<"12"<<endl;
//   }
//   if (menu == 13){
//     //the first item
//     cout<<"13"<<endl;
//   }
//   if (menu == 14){
//     //the last item
//     cout<<"14"<<endl; 
//   }
//   else if (menu <= 0 or menu > 15) {
//     cout<<"Invalid Option, Please try again!\n"<<endl;
//   }
  
 //}
 return 0;
}