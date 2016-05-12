#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include <iostream>
#include <string>

template <typename Comparable>
class RedBlackTree;

template <typename Comparable>
class RedBlackNode
{
    friend class RedBlackTree<Comparable>;
//所有的成员都是private
private:
    RedBlackNode(const Comparable &theElement = Comparable(),
                 RedBlackNode *theLeft = NULL,
                 RedBlackNode *theRight = NULL,
                 int theColor = RedBlackTree<Comparable>::BLACK)
        : element(theElement), left(theLeft), right(theRight), color(theColor) {}

    //数据成员
    Comparable element;
    RedBlackNode *left;
    RedBlackNode *right;
    int color;
};

#endif // TREENODE_H_INCLUDED
