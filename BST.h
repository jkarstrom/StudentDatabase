#include "TreeNode.h"
#include "Faculty.h"
#include "Student.h"

template class <T>
class BST{
public:
    BST<T>();
    ~BST();
    // virtual ~BST() - when working with template classes

    void insert(int value); // which in this example is also our key
    bool search(int value, int action); // which in this example is also our key
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();

    TreeNode<T>* getSuccessor(TreeNode<T>*d);
    void printTree(TreeNode<T> *node);

private:
    TreeNode<T> *root;
};
