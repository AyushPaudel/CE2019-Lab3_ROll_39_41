#include <iostream>
#include "ArrayBST.h"

int main()
{
    ArrayBinarySearchTree a;
    std::cout << "The tree is" << (a.isEmpty()?" " : " not ")<< "empty"  << std::endl;
    a.add(2);
    a.add(1);
    a.add(3);
    a.add(6);
    a.add(8);
    a.add(9);
    a.add(4);
    a.add(5);
    a.add(7);
    a.add(10);

    std::cout << "INORDER TRAVERSAL:" << std::endl;
    a.inorder();

    std::cout << "SEARCH TEST" << std::endl;
    int search =6;
    std::cout << "Searching for " << search << (a.exists(search)?": found" : " not found") << std::endl;
    search = 7;
    std::cout << "Searching for " << search << (a.exists(search)?": found" : " not found") << std::endl;
    search = 12;
    std::cout << "Searching for " << search << (a.exists(search)?": found" : ": not found") << std::endl;

    std::cout << "REMOVAL TEST" << std::endl;
    int rem = 7;
    std::cout << "INORDER TEST AFTER REMOVAL OF " << rem << std::endl;
    a.remove(rem);
    a.inorder();
    rem = 6;
    std::cout << "INORDER TEST AFTER REMOVAL OF " << rem << std::endl;
    a.remove(rem);
    a.inorder();

}
