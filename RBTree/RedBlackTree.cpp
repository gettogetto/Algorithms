#include "RedBlackTree.h"

//���������
template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree(const Comparable & negInf)
{
    nullNode = new RedBlackNode<Comparable>;
    //nullNode �������ӽڵ㶼ָ���Լ�
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

/**�������ӵĲ��� ** insert **/
template <typename Comparable>
void RedBlackTree<Comparable>::insert(const Comparable &x)
{
    current = parent = grand = great = header;
    nullNode->element = x;

    while (current->element != x)
    {
        //���游��Ϊ���游, ���׳�Ϊ�游, �Լ���Ϊ����
        //ÿ���ڵ㶼�ɳ�һ��
        great = grand;
        grand = parent;
        parent = current;
        current = (x < current->element) ? current->left : current->right;

        //����1. ���current�ڵ���������ɫ����
        if ((current->left->color == RED) && (current->right->color == RED))
            handleReorient( x );
    }

    //������а�����ͬ��Ԫ��
    if (current != nullNode)
        throw DuplicateItemException();

    current = new Node(x, nullNode, nullNode);
    if (x < parent->element)
        parent->left = current;
    else
        parent->right = current;

    //+ ����2. ����²���Ľڵ��ƻ��˺�ڹ���
    handleReorient( x );
}

/**�Զ�ƽ�⺯��:
    [1]����Ⱦɫ
    [2]�Զ���ת
*/
template <typename Comparable>
void RedBlackTree<Comparable>::handleReorient(const Comparable & item)
{
    // ��current�ڵ�Ⱦ�ɺ�ɫ
    current->color = RED;
    // ��current��left��right�ڵ�Ⱦ�ɺ�ɫ
    current->left->color = current->right->color = BLACK;

    // ���current�ڵ�ĸ��ڵ�Ҳ�Ǻ�� -> ����ת or ˫��ת
    if( parent->color == RED )
    {
        //�����游(үү)����ɫȾ�ɺ�ɫ
        grand->color = RED;

        //Ȼ���ж��²���Ľڵ��Ƿ����ڲ�����?
        //�����, ������һ����ת->����˫��ת

        //ifע��: ����ýڵ�С��үү, С�ڰְ�, �����������ͬʱ����
        //��˵������үү��������
        if( (item < grand->element) != (item < parent->element) )
        {
            // ����grand(�游)�ڵ������ת
            parent = rotate( item, grand );  // Start double rotate
        }
        // ����great(���游)�ڵ������ת
        current = rotate( item, great );

        //�ǰ�ڵ�Ϊ��ɫ
        current->color = BLACK;
    }

    //���ڵ�����Ǻ�ɫ��
    header->right->color = BLACK; // Make root black
}

// �Զ��жϲ�������ת����
template <typename Comparable>
typename RedBlackTree<Comparable>::Node *
RedBlackTree<Comparable>::rotate(const Comparable &item,
                                 Node *theParent )
{
    //λ��theParent��������
    if( item < theParent->element )
    {
        //���Ϊ��, ��˵��theParent->left������,
        //����, ���Һ���
        item < theParent->left->element ?
        //���theParent�����һ������, ����theParent->left
        //Ϊ��, ����ת
        rotateWithLeftChild( theParent->left )  :  // LL
        //���theParent�ұ���һ������, ����theParent->left
        //Ϊ��, ����ת
        rotateWithRightChild( theParent->left ) ;  // LR

        return theParent->left;     //����������
    }
    else    //λ��������
    {
        //���Ϊ��, ��˵��theParent->right������,����ת
        //����, ���Һ���, ����ת
        item < theParent->right->element ?
        rotateWithLeftChild( theParent->right ) :  // RL
        rotateWithRightChild( theParent->right );  // RR

        return theParent->right;    //����������
    }
}

/** ��(��)��ת **/
template <typename Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node *& k2)
{
    Node *k1 = k2->left;
    k2->left = k1->right;

    k1->right = k2;
    k2 = k1;
}

/** ��(��)��ת **/
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

        //��� x == iter->element
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
        // һֱ������
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
        // һֱ������
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
    //t == t->left��ʱ��, �ǵ�t==nullNodeʱ
    if (t != t->left)
    {
        reclainMemory(t->left);
        reclainMemory(t->right);
        delete t;
    }
}
