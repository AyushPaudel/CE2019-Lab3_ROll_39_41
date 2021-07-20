 
#pragma once 

class AbstractBST{
    public:
    virtual bool isEmpty()=0;
    virtual void add(int key) = 0;
    virtual void max(int &output) = 0;
    virtual void min(int &output) = 0;
    virtual bool exists( int searchKey) = 0;
    virtual void inorder() = 0;
    


};