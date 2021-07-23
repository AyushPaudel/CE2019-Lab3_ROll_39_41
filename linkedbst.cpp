#include <iostream>
using namespace std;
// code written by roll no. 39 Bishwa Pangeni
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node *root,int val)
{   
    if (root == NULL)
    {
        return new Node(val);
    }
    
    if(val < root->data)
    {
        root->left = insertBST(root->left, val);
    }else
    {
        // val > root->data;
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* searchProcess(Node *root,int key)
{   
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchProcess(root->left,key);
    }
    return searchProcess(root->right,key);  // if root->data < key
}
void SearchInBST(Node* root, int data)
{   cout << "Searching "<< data << " in BST..." << endl;
    if(searchProcess(root,data))
    {
        cout << "key " << data<<" exists in BST." << endl;
    }else
    {
        cout << "Key " << data<<" doesn't exist in BST." << endl;
    }
}
Node* Inordersuccesor(Node* root){
    Node* current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
Node* DeleteInBST(Node *root, int key)
{
    if(key < root->data)
    {
        root->left = DeleteInBST(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = DeleteInBST(root->right,key);
    }
    else{
        if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //This code is written for the case where the particular node which is to be deleted has two child.
        Node* temp = Inordersuccesor(root->right);
        root->data = temp->data;
        root->right = DeleteInBST(root->right,temp->data);
    }
    return root;
}
int main()
{   
    Node *root = NULL;
    cout << endl;
    root = insertBST(root, 20);
    insertBST(root,1);
    insertBST(root,30);
    insertBST(root,10);
    insertBST(root,5);
    insertBST(root,25);
    insertBST(root,15);
    insertBST(root,35);
    inorder(root);
    cout << endl;
    SearchInBST(root,0);
    cout << endl;
    SearchInBST(root,5);
    cout << endl;
    root = DeleteInBST(root,5);
    cout << "Deleting the key from BST..." << endl;
    inorder(root);
    cout << endl;
    return 0;
}
