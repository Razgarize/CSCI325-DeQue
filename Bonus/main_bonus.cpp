#include <iostream>
#include <string>
#include "Template_deque.h"

using namespace std;

int main() {
    Deque<int> d;
    std::cout << "Test" << std::endl;
    //  for(int i = 0; i < 199; i++)
    // {
    //     cout << "Capacity: " << d.get_capacity() << endl;
    //     cout << i << " " << endl;
    //     d.push_element_front(i);
    // }
     d.push_element_front(200);
     d.printBlockMap();
     cout << "Test" << endl;
     d.push_element_back(201);
     d.push_element_back(202);
     d.push_element_front(199);
     d.push_element_front(198);
     d.push_element_front(197);
     d.push_element_front(196);
     d.printBlockMap();
     d.push_element_front(195);
     cout << "Test" << endl;
     d.printBlockMap();
    // cout << "Front: ";
    // d.get_front();
    cout << "Hello, World!" << endl;
    return 0;
}
