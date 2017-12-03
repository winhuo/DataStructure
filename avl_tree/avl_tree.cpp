#include "avl_tree.h"
int AvlTree::height(AvlTreeNode *n)
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
AvlTreeNode* AvlTree::_leftRotation(AvlTreeNode *n)
{
    AvlTreeNode * n_1=n->rightChild;
    n->rightChild=n_1->leftChild;
    n_1->leftChild=n;
    n->height=(height(n->leftChild)>height(n->rightChild)?height(n->leftChild):height(n->rightChild))+1;
    n_1->height=(height(n_1->leftChild)>height(n_1->rightChild)?height(n_1->leftChild):height(n_1->rightChild))+1;

    return n_1;
}
AvlTreeNode* AvlTree::_rightRotation(AvlTreeNode *n)
{
    AvlTreeNode * n_1=n->leftChild;
    n->leftChild=n_1->rightChild;
    n_1->rightChild=n;
    n->height=(height(n->leftChild)>height(n->rightChild)?height(n->leftChild):height(n->rightChild))+1;
    n_1->height=(height(n_1->leftChild)>height(n_1->rightChild)?height(n_1->leftChild):height(n_1->rightChild))+1;

    return n_1;
}
AvlTreeNode* AvlTree::_rightLeftRotation(AvlTreeNode *n)
{
    n->rightChild=_rightRotation(n->rightChild);
    return _leftRotation(n);
}
AvlTreeNode* AvlTree:: _leftRightRotation(AvlTreeNode *n)
{
    n->leftChild=_leftRotation(n->leftChild);
    return _rightRotation(n);
}
AvlTreeNode* AvlTree::insert(AvlTreeNode *&n,int k)
{
    if(!n)
    {
        n=new AvlTreeNode();
        n->key=k;
    }
    if(k>n->key)
    {
        n->rightChild=insert(n->rightChild,k);
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
        n->leftChild=insert(n->leftChild,k);
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
    n->height=(height(n->leftChild)>height(n->rightChild)?height(n->leftChild):height(n->rightChild))+1;
    return n;
}
AvlTreeNode* AvlTree:: remove(AvlTreeNode *n,int key)
{
    if (n)
        {
            if (key == n->key)
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
                        AvlTreeNode* p = min(n->rightChild);
                        n->key = p->key;
                        n->rightChild = remove(n->rightChild, p->key);
                    }

                }
                else
                {

                    if (n->leftChild != NULL)
                        n = n->leftChild;
                    else if (n->rightChild != NULL)
                        n = n->rightChild;

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
                        n = _rightLeftRotation(n);
                        n = _leftRotation(n);
                }
            }
            return n;
        }
        return NULL;
}
AvlTreeNode* AvlTree::max(AvlTreeNode *n)
{
    if(n)
    {
        while(n->rightChild)
        {
            n=n->rightChild;
        }
        return n;
    }
    return NULL;
}
AvlTreeNode* AvlTree::min(AvlTreeNode *n)
{
    if(n)
    {
        while(n->leftChild)
        {
            n=n->leftChild;
        }
        return n;
    }
    return NULL;
}
