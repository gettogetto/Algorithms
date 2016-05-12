#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "TreeNode.h"
#include "MyException.h"
#include "Wrapper.h"

template <typename Comparable>
class RedBlackTree
{
//���Ͷ���
public:
    typedef RedBlackNode<Comparable> Node;
    enum COLOR {RED, BLACK};

//���ŵĽӿ�
public:
    explicit RedBlackTree(const Comparable & negInf);
    ~RedBlackTree();

    void insert(const Comparable &x);
    bool isEmpty() const;
    void makeEmpty();

    Gref<Comparable> find(const Comparable & x) const;
    Gref<Comparable> findMin() const;
    Gref<Comparable> findMax() const;

//ʵ�õ�˽�в���
private:
    //�Զ�����: [1]����Ⱦɫ; [2]:�Զ���ת
    void handleReorient(const Comparable &item);
    //�Զ���ת����(������ת�Ժ��theParent�����ĸ�)
    Node *rotate(const Comparable & item, Node *theParent);

    /**����ת**/
    //����ת(�����Һ���)
    void rotateWithLeftChild(Node *& k2);
    //����ת(��������)
    void rotateWithRightChild(Node *& k1);

    //�ݹ�ɾ�����нڵ�
    void reclainMemory(Node *t) const;

private:
    //ָ��������ͷ(α���ڵ�)
    Node *header;
    Node *nullNode;

    //��insertʱʹ��
    Node *current;  //��ǰ�ڵ�
    Node *parent;   //���ڵ�
    Node *grand;    //�游�ڵ�
    Node *great;    //���游�ڵ�
};

#endif // REDBLACKTREE_H_INCLUDED
