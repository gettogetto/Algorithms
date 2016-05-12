#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "TreeNode.h"
#include "MyException.h"
#include "Wrapper.h"

template <typename Comparable>
class RedBlackTree
{
//类型定义
public:
    typedef RedBlackNode<Comparable> Node;
    enum COLOR {RED, BLACK};

//开放的接口
public:
    explicit RedBlackTree(const Comparable & negInf);
    ~RedBlackTree();

    void insert(const Comparable &x);
    bool isEmpty() const;
    void makeEmpty();

    Gref<Comparable> find(const Comparable & x) const;
    Gref<Comparable> findMin() const;
    Gref<Comparable> findMax() const;

//实用的私有操作
private:
    //自动处理: [1]重新染色; [2]:自动旋转
    void handleReorient(const Comparable &item);
    //自动旋转函数(返回旋转以后的theParent子树的根)
    Node *rotate(const Comparable & item, Node *theParent);

    /**单旋转**/
    //向右转(带着右孩子)
    void rotateWithLeftChild(Node *& k2);
    //向左转(带着左孩子)
    void rotateWithRightChild(Node *& k1);

    //递归删除所有节点
    void reclainMemory(Node *t) const;

private:
    //指向红黑树的头(伪根节点)
    Node *header;
    Node *nullNode;

    //在insert时使用
    Node *current;  //当前节点
    Node *parent;   //父节点
    Node *grand;    //祖父节点
    Node *great;    //曾祖父节点
};

#endif // REDBLACKTREE_H_INCLUDED
