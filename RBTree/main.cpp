#include "RedBlackTree.h"
#include "RedBlackTree.cpp"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int NEG_INF = -999999;
    RedBlackTree<int> tree(NEG_INF);

    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(10);
    tree.insert(55);
    tree.insert(88);
    tree.insert(200);
    tree.insert(100);
    tree.insert(70);
    tree.insert(80);
    tree.insert(650);

    Gref<int> g = tree.findMin();
    cout << "Min = " << g.get() << endl;
    g = tree.findMax();
    cout << "Max = " << g.get() << endl;

    int searchVal;
    while (cin >> searchVal)
    {
        g = tree.find(searchVal);
        if (g.isNull())
            cout << "not found" << endl;
        else
            cout << g.get() << " founded" << endl;
    }

    tree.makeEmpty();
    if (tree.isEmpty())
    {
        cout << "is Empty" << endl;
    }
    else
    {
        cout << "not Empty" << endl;
    }

    return 0;
}
