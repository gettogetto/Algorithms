#include "RedBlackTree.h"

//红黑树构造
template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree(const Comparable & negInf)
{
    nullNode = new RedBlackNode<Comparable>;
    //nullNode 的左右子节点都指向自己
    nullNode->left = nullNode->right = nullNode;

    header = new RedBlackNode<Comparable>(negInf, nullNode, nullNode);
}

template <typename Comparable>
RedBlackTree<Comparable>::~RedBlackTree()
{
    if (!isEmpty())
        makeEmpty();

    delete nullNode;
    delete header;
}

/**红黑树最复杂的操作 ** insert **/
template <typename Comparable>
void RedBlackTree<Comparable>::insert(const Comparable &x)
{
    current = parent = grand = great = header;
    nullNode->element = x;

    while (current->element != x)
    {
        //让祖父成为曾祖父, 父亲成为祖父, 自己成为父亲
        //每个节点都成长一辈
        great = grand;
        grand = parent;
        parent = current;
        current = (x < current->element) ? current->left : current->right;

        //处理1. 如果current节点有两个红色孩子
        if ((current->left->color == RED) && (current->right->color == RED))
            handleReorient( x );
    }

    //如果树中包含相同的元素
    if (current != nullNode)
        throw DuplicateItemException();

    current = new Node(x, nullNode, nullNode);
    if (x < parent->element)
        parent->left = current;
    else
        parent->right = current;

    //+ 处理2. 如果新插入的节点破坏了红黑规则
    handleReorient( x );
}

/**自动平衡函数:
    [1]重新染色
    [2]自动旋转
*/
template <typename Comparable>
void RedBlackTree<Comparable>::handleReorient(const Comparable & item)
{
    // 将current节点染成红色
    current->color = RED;
    // 将current的left和right节点染成黑色
    current->left->color = current->right->color = BLACK;

    // 如果current节点的父节点也是红的 -> 单旋转 or 双旋转
    if( parent->color == RED )
    {
        //则将其祖父(爷爷)的颜色染成红色
        grand->color = RED;

        //然后判断新插入的节点是否是内部孙子?
        //如果是, 则增加一次旋转->构成双旋转

        //if注释: 如果该节点小于爷爷, 小于爸爸, 这两种情况不同时满足
        //则说明其是爷爷的内孙子
        if( (item < grand->element) != (item < parent->element) )
        {
            // 则依grand(祖父)节点进行旋转
            parent = rotate( item, grand );  // Start double rotate
        }
        // 则依great(曾祖父)节点进行旋转
        current = rotate( item, great );

        //令当前节点为黑色
        current->color = BLACK;
    }

    //根节点必须是黑色的
    header->right->color = BLACK; // Make root black
}

// 自动判断并进行旋转函数
template <typename Comparable>
typename RedBlackTree<Comparable>::Node *
RedBlackTree<Comparable>::rotate(const Comparable &item,
                                 Node *theParent )
{
    //位于theParent的左子树
    if( item < theParent->element )
    {
        //如果为真, 则说明theParent->left有左孩子,
        //否则, 有右孩子
        item < theParent->left->element ?
        //如果theParent左边有一棵子树, 则以theParent->left
        //为轴, 向右转
        rotateWithLeftChild( theParent->left )  :  // LL
        //如果theParent右边有一棵子树, 则以theParent->left
        //为轴, 向左转
        rotateWithRightChild( theParent->left ) ;  // LR

        return theParent->left;     //返回左子树
    }
    else    //位于右子树
    {
        //如果为真, 则说明theParent->right有左孩子,往右转
        //否则, 有右孩子, 往左转
        item < theParent->right->element ?
        rotateWithLeftChild( theParent->right ) :  // RL
        rotateWithRightChild( theParent->right );  // RR

        return theParent->right;    //返回右子树
    }
}

/** 右(单)旋转 **/
template <typename Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node *& k2)
{
    Node *k1 = k2->left;
    k2->left = k1->right;

    k1->right = k2;
    k2 = k1;
}

/** 左(单)旋转 **/
template <typename Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node *& k1)
{
    Node * k2 = k1->right;
    k1->right = k2->left;

    k2->left = k1;
    k1 = k2;
}

template <typename Comparable>
Gref<Comparable> RedBlackTree<Comparable>::find(const Comparable &x) const
{
    if (isEmpty())
        return Gref<Comparable>();

    nullNode->element = x;
    Node *iter = header->right;

    while (true)
    {
        if (x < iter->element)
            iter = iter->left;
        else if (x > iter->element)
            iter = iter->right;

        //如果 x == iter->element
        else if (iter != nullNode)
            return Gref<Comparable>(iter->element) ;
        else
            return Gref<Comparable>();
    }
}

template <typename Comparable>
Gref<Comparable> RedBlackTree<Comparable>::findMax() const
{
    if (isEmpty())
        return Gref<Comparable>();

    Node *iter = header->right;
    while (iter->right != nullNode)
    {
        // 一直向右走
        iter = iter->right;
    }

    return Gref<Comparable>(iter->element);
}

template <typename Comparable>
Gref<Comparable> RedBlackTree<Comparable>::findMin() const
{
    if (isEmpty())
        return Gref<Comparable>();

    Node *iter = header->right;
    while (iter->left != nullNode)
    {
        // 一直向左走
        iter = iter->left;
    }

    return Gref<Comparable>(iter->element);
}


template <typename Comparable>
bool RedBlackTree<Comparable>::isEmpty() const
{
    if (header->right == nullNode)
        return true;
    return false;
}

template <typename Comparable>
void RedBlackTree<Comparable>::makeEmpty()
{
    reclainMemory(header->right);
    header->right = nullNode;
}

template <typename Comparable>
void RedBlackTree<Comparable>::reclainMemory(Node *t) const
{
    //t == t->left的时候, 是当t==nullNode时
    if (t != t->left)
    {
        reclainMemory(t->left);
        reclainMemory(t->right);
        delete t;
    }
}
