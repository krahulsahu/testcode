#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;

    void addNode(int value, Node *node)
    {
        if (value < node->data)
        {
            if (node->left != NULL)
            {
                addNode(value, node->left);
            }
            else
            {
                node->left = new Node(value);
            }
        }
        else
        {
            if (node->right != NULL)
            {
                addNode(value, node->right);
            }
            else
            {
                node->right = new Node(value);
            }
        }
    }

    void printInOrder(Node *node)
    {
        if (node->left != NULL)
        {
            printInOrder(node->left);
        }
        cout << node->data << " ";
        if (node->right != NULL)
        {
            printInOrder(node->right);
        }
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    void addNode(int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            addNode(value, root);
        }
    }

    void printInOrder()
    {
        if (root != NULL)
        {
            printInOrder(root);
            cout << endl;
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.addNode(5);
    tree.addNode(3);
    tree.addNode(7);
    tree.addNode(1);
    tree.addNode(4);
    tree.addNode(6);
    tree.addNode(8);

    tree.printInOrder();

    return 0;
}
