#ifndef ArrayBST_h
#define ArrayBST_h

#define MAX_NUM_NODES 10000

#include "AbstractBST.h"

struct ArrayNode {
    int key;
    
    ArrayNode(int key) : key(key) {}
};

class ArrayBinarySearchTree : public AbstractBST {

public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();
    
    // Checks if the BST is empty
    bool isEmpty();
    void add(int key);
    
    void max(int &output);
    void min(int &output);
    
    bool exists(int targetKey);

    void remove(int deleteKey);

    void inorder();
    int index(int targetKey);

private:
    ArrayNode* nodes[MAX_NUM_NODES];
    ArrayNode *newData;   
    void inorder(int index, char sep = ' ');

};

#endif /* ArrayBST_h */