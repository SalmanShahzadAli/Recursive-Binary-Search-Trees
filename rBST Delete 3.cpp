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
    Node *getRoot()
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
    Node *rInsert(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
        {
            return new Node(value);
        }
        if (value > currentNode->value)
        {
            currentNode->right = rInsert(currentNode->right, value);
        }
        else if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        return currentNode;
    }
    void rInsert(int value)
    {
        if (root == nullptr)
            root = new Node(value);
        rInsert(root, value);
    }
    int minValue(Node *newNode)
    {
        while (newNode->left != nullptr)
        {
            newNode = newNode->left;
        }
        return newNode->value;
    }
    Node *deleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr;

        if (value < currentNode->value)
        {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else
        {
            if (currentNode->right == nullptr && currentNode->left == nullptr)
            {
                delete (currentNode);
                return nullptr;
            }
            else if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete (currentNode);
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                Node *temp = currentNode->left;
                delete (currentNode);
                return temp;
            }
            else
            {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right,subTreeMin);
            }
        }
        return currentNode;
    }
    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }
    
};

int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();
    myBST->rInsert(2);
    myBST->rInsert(1);
    myBST->rInsert(3);


    cout << "\nBefore Deleting (2) Node:\n";
    cout << "--------------------";
    cout << "\nRoot: " << myBST->getRoot()->value << endl;
    cout << "Root->left: " << myBST->getRoot()->left->value << endl;
    cout << "Root->right: " << myBST->getRoot()->right->value << endl; 

    myBST->deleteNode(2);

    cout << "\n\nAfter Deleting (2) Node:\n";
    cout << "-------------------";
    cout << "\nRoot: " << myBST->getRoot()->value << endl;
    cout << "Root->left: " << myBST->getRoot()->left->value << endl;
    cout << "Root->right: " << myBST->getRoot()->right << endl; 
    return 0;
}