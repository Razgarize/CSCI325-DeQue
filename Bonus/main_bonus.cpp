#include <iostream>
#include <string>
#include "Template_deque.h"

using namespace std;

template <typename DequeT>
void Test(DequeT &d);

template <typename DequeT>
void Test2(DequeT &d);

template <typename DequeT>
void TestString(DequeT &d);

int main() {
    Deque<int> d;
    d.push_element_front(90);
    d.printBlockMap();
    d.get_front();
    d.pop_front();
    d.printBlockMap();
    d.get_front();
    d.push_element_back(91);
    d.push_element_front(90);
    d.printBlockMap();
    //Test2(d);
    //Deque<char> t;
    //Test2(t);
    //TestString(t);
    // cout << "Front: ";
    // d.get_front();
    cout << "Hello, World!" << endl;
    return 0;
}




template <typename DequeT>
void Test2(DequeT &d)
{
    for(int i = 33; i < 126; i++)
    {
        // cout << "Capacity: " << d.get_capacity() << endl;
        // cout << "Element: " << i << " " << endl;
        d.push_element_front(i);
    }
    //d.printBlockMap();
    // for(int i = 0; i < 1; i++)
    // {
    //     // cout << "Capacity: " << d.get_capacity() << endl;
    //     // cout << "Element: " << i << " " << endl;
    //     d.push_element_back(i);
    // }
    d.printBlockMap();
    cout << endl;
    cout << "Random Access: " << d[2] << endl;
}



template <typename DequeT>
void Test(DequeT &d)
{
        std::cout << "Test" << std::endl;
    //  for(int i = 0; i < 199; i++)
    // {
    //     cout << "Capacity: " << d.get_capacity() << endl;
    //     cout << i << " " << endl;
    //     d.push_element_front(i);
    // }
    cout << "Map Size: " << d.get_MapSize() << endl;
    cout << "Map Capacity: " << d.get_capacity() << endl;
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
     d.push_element_back(203);
    d.push_element_back(204);
    d.push_element_back(205);
    d.push_element_back(206);
    d.push_element_front(240);
     cout << "Test" << endl;
     d.printBlockMap();
}
