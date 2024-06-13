#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
        string info;
        string* lchild;
        string* rchild;

        //konstruksi buat kelas
        node(string i, node* l, node* r);
        {
            info = i;
            lchild = l;
            rchild = r;
        }
};

class binarytree
{
    public:
    node* root;
    binarytree()
    {
        root = nullptr; //inisialisasi root sebagai titik null
    }
    void insert(string element) //memasukan sebuah node ke dalam binary tree
    {
        node*newnode = new node(element, nullptr, nullptr); //mengalokasikan node baru 
        newnode->info = element;
        newnode->lchild = nullptr;
        newnode->rchild = nullptr;

        node* parent = nullptr;
        node* currentnode = nullptr;
        search(element, parent, currentnode);

        if (parent = nullptr)
    }
}