#include<iostream>
using namespace std;

class AvlTreeNode
{
public:
    int  key;
    int  height;
    AvlTreeNode *rightChild;
    AvlTreeNode *leftChild;
public:
    AvlTreeNode()
    {
        this->key=0;
        this->height=0;
        this->leftChild=NULL;
        this->rightChild=NULL;
    }
    AvlTreeNode(int k,AvlTreeNode* l,AvlTreeNode *r)
    {
        this->key=k;
        this->height=0;
        this->leftChild=l;
        this->rightChild=r;
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

    int height(AvlTreeNode *n)
    {
        if(n)
        {
            return n->height;
        }
        else
        {
            return 0;
        }
    }
    AvlTreeNode* _leftRotation(AvlTreeNode *n)
    {
        AvlTreeNode * n_1=n->rightChild;
        n->rightChild=n_1->leftChild;
        n_1->leftChild=n;
        n->height=(height(n->leftChild)>height(n->rightChild)?height(n->leftChild):height(n->rightChild))+1;
        n_1->height=(height(n_1->leftChild)>height(n_1->rightChild)?height(n_1->leftChild):height(n_1->rightChild))+1;

        return n_1;
    }
    AvlTreeNode* _rightRotation(AvlTreeNode *n)
    {
        AvlTreeNode * n_1=n->leftChild;
        n->leftChild=n_1->rightChild;
        n_1->rightChild=n;
        n->height=(height(n->leftChild)>height(n->rightChild)?height(n->leftChild):height(n->rightChild))+1;
        n_1->height=(height(n_1->leftChild)>height(n_1->rightChild)?height(n_1->leftChild):height(n_1->rightChild))+1;

        return n_1;
    }
    AvlTreeNode* _rightLeftRotation(AvlTreeNode *n)
    {
        n->rightChild=_rightRotation(n->rightChild);
        return _leftRotation(n);
    }
    AvlTreeNode* _leftRightRotation(AvlTreeNode *n)
    {
        n->leftChild=_leftRotation(n->leftChild);
        return _rightRotation(n);
    }

    AvlTreeNode* insert(AvlTreeNode *n,int k)
    {
        if(!n)
        {
            n=new AvlTreeNode();
            n->key=k;
        }
        if(k>n->key)
        {
            n->rightChild=insert(n->rightChild,key);
            if(height(n->rightChild)-height(n->leftChild)==2)
            {
                if(k>n->rightChild->key)
                {
                    n=_leftRotation(n);
                }
                else if(k<n->rightChild->key)
                {
                    n=_rightLeftRotation(n);
                }
            }
        }
        if(k<n->key)
        {
            n->leftChild=insert(n->leftChild,key);
            if(height(n->leftChild)-height(n->rightChild)==2)
            {
                if(k>n->leftChild->key)
                {
                    n=_rightRotation(n);
                }
                else if(k<n->leftChild->key)
                {
                    n=_leftRightRotation(n);
                }
            }
        }
        n->height=(height(n_1->leftChild)>height(n_1->rightChild)?height(n_1->leftChild):height(n_1->rightChild))+1;
        return n;
    }
    AvlTreeNode* remove(AvlTreeNode *n,int key)
    {
        if (!n)
            {
                if (key == pnode->key)
                {
                    if (n->leftChild!=NULL&&n->rightChild !=NULL)
                    {

                        if (height(n->leftChild) > height(n->rightChild))
                        {

                            AvlTreeNode* p = max(n->leftChild);
                            n->key = p->key;
                            n->leftChild = remove(n->leftChild, p->key);
                        }
                        else
                        {
                            AvlTreeNode* p = mini(n->rightChild);
                            n->key = p->key;
                            n->rightChild = remove(n->rightChild, ps->key);
                        }

                    }
                    else
                    {
                        AvlTreeNode * p = n;
                        if (n->leftChild != NULL)
                            n = n->leftChild;
                        else if (n->rightChild != NULL)
                            n = n->rightChild;
                        delete p;
                        return NULL;
                    }

                }
                else if (key > n->key)
                {
                    n->rightChild =  remove(n->rightChild, key);
                    if (height(n->leftChild) - height(n->rightChild) == 2)
                    {
                        if (height(n->leftChild->rightChild)>height(n->leftChild->leftChild))
                            n = _leftRightRotation(n);
                        else
                            n = _rightRotation(n);
                    }
                }
                else if (key < n->key)
                {
                    n->leftChild= remove(n->leftChild, key);

                    if (height(n->rightChild) - height(n->leftChild) == 2)
                    {
                        if (height(n->rightChild->leftChild)>height(n->rightChild->rightChild))
                            n = _rightLeftRotation(pnode);
                            n = _leftRotation(pnode);
                    }
                }
                return pnode;
            }
            return nullptr;
    }
    AvlTreeNode* max(AvlTreeNode *n)
    {
        if(!n)
        {
            while(!n->rightChild)
            {
                n=n->rightChild;
            }
            return n;
        }
        return NULL;
    }
    AvlTreeNode* min(AvlTreeNode *n)
    {
        if(!n)
        {
            while(!n->leftChild)
            {
                n=n->leftChild;
            }
            return n;
        }
        return NULL;
    }

    void test()
    {

    }
};

