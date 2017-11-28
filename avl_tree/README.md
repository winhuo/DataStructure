##AVL树的插入和删除操作

*曦剑创建于2017年11月28日*

**目录 (Table of Contents)**

*AVL树的节点元素

*AVL树中函数的作用

*AVL旋转的原理图示链接

###AVL树的节点元素

    public:
        int  key;  //节点的键值
        int  height;  //节点的高度
        AvlTreeNode *rightChild;   //指向右孩子的指针
        AvlTreeNode *leftChild;     //指向左孩子的指针
### AVL树中函数的作用

*下列注释中所指的树是以传入参数作为根节点的树*

    int height(AvlTreeNode *n)
    //获取树的高度；
    AvlTreeNode* _leftRotation(AvlTreeNode *n)
    //对树进行左旋
    AvlTreeNode* _rightRotation(AvlTreeNode *n)
    //对树进行右旋
    AvlTreeNode* _rightLeftRotation(AvlTreeNode *n)
    //对树进行右左旋
    AvlTreeNode* _leftRightRotation(AvlTreeNode *n)
    //对树进行左右旋
    AvlTreeNode* insert(AvlTreeNode *n,int k)
    //对树进行插入操作
    AvlTreeNode* remove(AvlTreeNode *n,int key)
    //删除给定值的节点
    AvlTreeNode* max(AvlTreeNode *n)
    //求树中的最大元素
    AvlTreeNode* min(AvlTreeNode *n)
    //求树的最小节点
    void test()
    //测试函数
	

###AVL旋转的原理图示链接

https://www.cnblogs.com/skywang12345/p/3576969.html

### End