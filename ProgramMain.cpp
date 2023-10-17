#include <iostream>
#include "DoublyLinkedList.h"
int main()
{
    DoublyLinkedList<int> list;
    for(int i = 0; i < 10; i++)
    {
        int num;
        std::cin >> num;
        list.push_back(num);
    }

    list.print();
}