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
    bool search(int value); // which in this example is also our key
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode* getMin();
    TreeNode* getMax();

    TreeNode* getSuccessor(TreeNode *d);
    void printTree(TreeNode *node);

private:
    TreeNode<T> *root;
};
