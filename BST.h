#ifndef BST_H
#define BST_H
#include "TreeNode.h"

template <class T>
class BST{
public:
    BST<T>();
    ~BST();
    // virtual ~BST() - when working with template classes

    void insert(int id, T* value); // which in this example is also our key
    bool search(int id, int action = 0, T* soul = NULL); // which in this example is also our key
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();

    TreeNode<T>* getSuccessor(TreeNode<T>*d);
    void printTree();

private:
    TreeNode<T> *root;
};
#endif
