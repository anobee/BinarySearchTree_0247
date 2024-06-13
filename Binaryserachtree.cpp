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
    binary tree()
    {
        root = nullptr; //inisialisasi root sebagai titik null
