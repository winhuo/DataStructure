#include<iostream>
using namespace std;

class AvlTreeNode
{
private:
    int  key;   //jianzhi;
    int  height;
    AvlTreeNode *righChild;
    AvlTreeNode *leftChild;
public:
    AvlTreeNode()
    {
        this->key=0;
        this->height=0;
        this->leftChild=NULL;
        this->rightChild=NULL;
    }
    int get_key()
    {
        return this->key;
    }
    int get_height()
    {
        return this->height;
    }
    void put_key(int k)
    {
        this->key=k;
    }
    void put_height(int h)
    {
        this->height=h;
    }
    AvlTreeNode*get_leftChild()
    {
        return this->leftChild;
    }
    AvlTreeNode*get_rightChild()
    {
        return this->rightChild;
    }
    void put_rightChild(AvlTreeNode*r)
    {
        this->righChild=r;
    }
    void put_leftChild(AvlTreeNode*l)
    {
        this->leftChild=l;
    }


};
class AvlTree
{
private:
    AvlTreeNode *root;
public:
    AvlTree()
    {
        this->Root=NULL;
    }
    void preOrder(AvlTreeNode n)
    {
        if(n)
        {
            cout<<n.get_key()<<"  ";

        preOrder(n.get_leftChild());
        preOrder(n.get_rightChild());
        }
    }
    void insert(int key)
    {

    }
    void remove(int key)
    {

    }
    void change(int key)
    {

    }
    void test()
    {

    }
};
