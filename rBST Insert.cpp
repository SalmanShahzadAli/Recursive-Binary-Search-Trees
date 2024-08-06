#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *root;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};
class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    Node* getRoot()
    {
        return root;
    }
    bool rContains(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return false;
        }
        if (currentNode->value == value)
        {
            return true;
        }
        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else
        {
            return rContains(currentNode->right, value);
        }
    };
    bool rContains(int value)
    {
        return rContains(root, value);
    }
    Node* rInsert(Node* currentNode , int value)
    {
       if (currentNode == nullptr)
       {
        return new Node(value);
       }
       if (value > currentNode->value)
       {
        currentNode->right = rInsert(currentNode->right , value);
       } else if (value < currentNode->value){
        currentNode->left = rInsert(currentNode->left , value);
       }
       return currentNode;
       
    }
    void rInsert(int value)
    {
        if (root == nullptr) root = new Node(value);
        rInsert(root,value);
    }
};

int main()
{
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->rInsert(2);
    myBST->rInsert(1);
    myBST->rInsert(3);
    
    cout << "\nRoot: " << myBST->getRoot()->value;
    cout << "\nRoot->left: " << myBST->getRoot()->left->value;
    cout << "\nRoot->right: " << myBST->getRoot()->right->value;




    return 0;
}