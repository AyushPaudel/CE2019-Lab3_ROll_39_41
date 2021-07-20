#include <iostream>
#include "ArrayBST.h"

int main()
{
    ArrayBinarySearchTree a;
    std::cout << "The tree is empty:" << a.isEmpty() << std::endl;
    a.add(2);
    a.add(1);
    a.add(3);
    a.add(6);
    a.add(8);
    a.add(9);
    a.add(4);
    a.add(6);
    a.add(7);
    a.add(10);
    a.inorder();
}
