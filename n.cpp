#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* leftchiId;
    Node* rightchiId;

    //Constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchiId = l;
        rightchiId = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //Initalizing ROOT to null
    }

    void insert(string element) //Insert a node in in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //Allocate memory for the new node
        newNode->info = element; //Assign value to the data field of the new node
        newNode->leftchiId = nullptr;//Make the left child of the new node point to NULL.
        newNode->rightchiId = nullptr; //Make the right child of the new node point to NULL.

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //Locate the node wich will be the parent of the node to be insert

        if (parent == nullptr) //If the parent is NULL(Tree is empty)
        {
            ROOT = newNode; //Mark the new node as ROOT.
            return; //Exit
        }

        if (element < parent->info) //If the value in the data field of the new node is les than that of the
        {
            parent->leftchiId = newNode; //Make the lift child of the parent point to the new node
        }
        else if (element > parent->info) //If the value in the data field of the new node is greater than that
        {
            parent->rightchiId = newNode; //Make the right child of the parent point to the new node 
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        //This function searches the currentNode of the specified Node as well as the currentNode of its parent
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchiId;
            else
                currentNode = currentNode->rightchiId;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchiId);
            cout << ptr->info << " ";
            inorder(ptr->rightchiId);
        }
    }


     void preorder(Node* ptr)
      {
        if (ROOT == NULL)
         {
             cout << "Tree is empty" << endl;
             return;
         }

         if (ptr != NULL)
         {
             cout << ptr->info << " ";
             inorder(ptr->leftchiId);
             inorder(ptr->rightchiId);
         }
     }

    void postorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            inorder(ptr->leftchiId);
            inorder(ptr->rightchiId);
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nmenu" << endl;
        cout << "1. implement insert option" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit " << endl;
        cout << "\nenter your choice(1-5) :" << endl;

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "enter a word";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }

        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }

        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }

        case '4':
        {
            x.postorder(x.ROOT);
            break;
        }

        case '5':
        {
            return 0;
        }

        }
    }
};