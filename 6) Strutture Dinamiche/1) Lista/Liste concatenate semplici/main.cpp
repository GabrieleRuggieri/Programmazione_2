#include <iostream>
#include "Linked_list.h"

int main()
{
    List<int> myList;

    // Insert elements into the list
    myList.insertTail(1);
    myList.insertTail(2);
    myList.insertTail(3);
    myList.insertTail(4);
    myList.insertTail(5);

    // Print the original list
    std::cout << "Original List:\n";
    std::cout << myList;

    // Invert the list
    myList.inverti();

    // Print the inverted list
    std::cout << "Inverted List:\n";
    std::cout << myList;

    return 0;
}
