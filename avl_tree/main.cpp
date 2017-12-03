#include "avl_tree.h"
int main()
{
    AvlTree a;
    for(int i=0;i<10;i++)
    {
        a.insert(a.Root,i);
    }
    a.show();
    a.insert(a.Root,10);
    a.show();
    a.remove(a.Root,5);
    a.show();
    return 0;
}
