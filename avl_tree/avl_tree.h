#include<iostream>
#include<queue>
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
public:
    AvlTreeNode *Root;
public:
    AvlTree()
    {
        this->Root=NULL;
    }
    AvlTreeNode *getRoot()
    {
        return this->Root;
    }
    void show()
    {
        queue<AvlTreeNode> q;
        AvlTreeNode *usingNode=(this->Root);
        if(usingNode)
        {
            q.push(*usingNode);

        }
        while(!q.empty())
        {
            cout<<(*usingNode).key<<"  ";
            q.pop();
            if((*usingNode).leftChild)
            {
                q.push(*((*usingNode).leftChild));
            }
            if((*usingNode).rightChild)
            {
                q.push(*((*usingNode).rightChild));
            }
            usingNode=&q.front();
        }
        cout<<endl;
    }

    int height(AvlTreeNode *n);
    AvlTreeNode* _leftRotation(AvlTreeNode *n);
    AvlTreeNode* _rightRotation(AvlTreeNode *n);
    AvlTreeNode* _rightLeftRotation(AvlTreeNode *n);
    AvlTreeNode* _leftRightRotation(AvlTreeNode *n);
    AvlTreeNode* insert(AvlTreeNode *&n,int k);
    AvlTreeNode* remove(AvlTreeNode *n,int key);
    AvlTreeNode* max(AvlTreeNode *n);
    AvlTreeNode* min(AvlTreeNode *n);

};

