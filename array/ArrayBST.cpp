#include <iostream>

#include "ArrayBST.h"

ArrayBinarySearchTree::ArrayBinarySearchTree() {
    for (int i = 0; i < MAX_NUM_NODES; i++) {
        nodes[i] = NULL;
    }
}
ArrayBinarySearchTree::~ArrayBinarySearchTree() 
{
    int i;

    for (i = 1; i <= MAX_NUM_NODES; i++)
    {

        delete this->nodes[i];
        this->nodes[i] = NULL;
    }
}

bool ArrayBinarySearchTree::isEmpty() {
    return this->nodes[1] == NULL ;
}

void ArrayBinarySearchTree::add(int key) {
    ArrayNode* newData(new ArrayNode(key));
    
    for (int i = 1; i < MAX_NUM_NODES; ) {
        ArrayNode* node = this->nodes[i];
        
        if (node == NULL) {
            this->nodes[i] = newData;
            break;
        } else if (node->key < key) {
            i = 2 * i + 1;
        } else {
            i = 2 * i;
        }
    }
    
}

bool ArrayBinarySearchTree::exists(int deleteKey) {
    
    int i = 1;
    bool found = false;
    while (i < MAX_NUM_NODES) {
        ArrayNode* node = this->nodes[i];
        if (node == NULL) {
            break;
        } else if (node->key == deleteKey) {
            found = true;
            break;
        } else if (node->key < deleteKey) {
            i = 2 * i + 1;
        } else {
            i = 2 * i;
        }
    }
    return found;
}

void ArrayBinarySearchTree::min(int &output) {
    
    if (isEmpty()) {
        std::cout << "The tree is empty!" << std::endl;
    } else {
        int i = 1;
        while (i < MAX_NUM_NODES) {
            if (nodes[2 * i] == NULL) {
                break;
            } else {
                i = 2 * i;
            }
        }
        if (i < MAX_NUM_NODES) {
            output = nodes[i]->key;
        }
    }
}



void ArrayBinarySearchTree::max(int &output) {
    
    if (isEmpty()) {
        std::cout << "The tree is empty!" << std::endl;
    } else {
        int i = 1;
        while (i < MAX_NUM_NODES) {
            if (nodes[2 * i + 1] == NULL) {
                break;
            } else {
                i = 2 * i + 1;
            }
        }
        if (i < MAX_NUM_NODES) {
            output = nodes[i]->key;
        }
    }
}

void ArrayBinarySearchTree::inorder() {
    this->inorder(1);
    std::cout << std::endl;
}

void ArrayBinarySearchTree::inorder(int index, char sep) {
    if (index < MAX_NUM_NODES && nodes[index] != NULL) {
        this->inorder(2 * index);
        std::cout << nodes[index]->key << sep;
        this->inorder(2 * index+1);
    }
}


int ArrayBinarySearchTree::index(int target)
{

    int i = 1;
    int index;
    while (i < MAX_NUM_NODES)
    {
        ArrayNode *node = this->nodes[i];
        if (node == NULL)
        {
            break;
        }
        else if (node->key == target)
        {
            index = i;
            break;
        }
        else if (node->key < target)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i;
        }
    }
    return index;
}

void ArrayBinarySearchTree::remove(int deleteKey)
{
    if (this->exists(deleteKey)) 
{
        int index_del_node = this->index(deleteKey);
        int index_min = this->index(deleteKey);
        int index_max = index_min;
        //when both left and right part are empty
        if (this->nodes[index_min * 2] == NULL && this->nodes[index_min * 2 + 1] == NULL)
        {
            this->nodes[index_min] = NULL;
        }

        else if (this->nodes[index_min * 2 + 1] != NULL)
        {
            index_min = index_min * 2 + 1;
          while (this->nodes[index_min] != NULL)
            {
                if (this->nodes[index_min * 2] != NULL)
                {
                    while (this->nodes[index_min * 2] != NULL)
                    {
                        index_min = index_min * 2;
                    }
                }
                this->nodes[index_del_node] = this->nodes[index_min];
                index_del_node = index_min;
                this->nodes[index_min] = NULL;
                if (this->nodes[index_min * 2 + 1] != NULL)
                {
                    index_min = index_min * 2 + 1;
                }
            }
        }
        else if (this->nodes[index_max * 2 + 1] == NULL)
        {
            index_max = index_max * 2;
            while (this->nodes[index_max] != NULL)
            {
                if (this->nodes[index_max * 2 + 1] != NULL)
              

                {
                    while (this->nodes[index_max * 2 + 1] != NULL)
                    {
                        index_max = index_max * 2 + 1;
                    }
                }

                this->nodes[index_del_node] = this->nodes[index_max];
                index_del_node = index_max;
                this->nodes[index_max] = NULL;
                if (this->nodes[index_max * 2] != NULL)
                {
                    index_max = index_max * 2;
                }
            }
        }
    }
}