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
        root = nullptr; //inisialisasi root sebagai titik NULL
    }
    void insert(string element) //memasukan sebuah node ke dalam binary tree
    {
        node* newnode = new node(element, nullptr, nullptr); //mengalokasikan node baru 
        newnode->info = element; //memsukan data baru pada node baru 
        newnode->lchild = nullptr; //membuat lchild sebagai titk NULL
        newnode->rchild = nullptr; //membuat rchild sebagai titik NULL

        node* parent = nullptr;
        node* currentnode = nullptr;
        search(element, parent, currentnode); //alokasikan node yang akan menjadi parent parent

        if (parent == nullptr)//jika parent is NULL(tree kosong)

        {
            root = newnode; //menandai newnode sebagai root
            return;//keluar
        }

        if (element < parent->info) //jika nilai data field pada node baru lebih kecil dari 
        {
            parent->leftchild = newnode;//membuat lchild dari parent menjadi point node baru 
        }

        else if(element > parent->info) // jika nilai dari data field node baru lebih besar dari 
        {
            parent->rchild = newnode;//membuar rchild dari parent sebagai node baru
        }
    }

    void search(string element, node*& parent, node*& currentnode)
    {
        //fungsi yang digunakan untuk mencari current node dari node yang di tentukan 
        currentnode = root;
        parent = NULL;
        while((currentnode != NULL)&&(currentnode->info!=element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->lchild;
                else
                    currentnode = currentnode->rchild;

        }
    }
    void inorder(node* ptr)
    {
        if ( root == NULL )
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->lchild);
            cout << ptr->info << "";
            inorder(ptr->rchild);
        }
    }

    void preorder(node* ptr)
    {
        if ( root == NULL )
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << "";
            preorder(ptr->lchild);
            preorder(ptr->rchild);
        }
    }

    void postorder(node* ptr)
    {
        if ( root == NULL )
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << "";
            postorder(ptr->lchild);
            postorder(ptr->rchild);
        }
    }
}