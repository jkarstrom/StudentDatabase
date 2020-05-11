#include "BST.h"

template<class T>
BST::BST(){

}

template<class T>
BST::~BST(){

}

template<class T>
void BST::insert(int value){
    TreeNode *node = new TreeNode(value);

    if(isEmpty){
        // empty tree
        root = node;
    }
    else{
        // not an empty tree
        TreeNode *curr = root; // start at the root
        TreeNode *parent;

        while(true){
            parent = curr;
            if(value < curr->key){
                // go left
                curr = curr->left;
                if(curr == NULL){
                    parent->left = node;
                    break;
                }
            }
            else{
                // go right
                curr = curr->right;
                if(curr == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template<class T>
bool BST::search(int value){
    if(isEmpty()){
        return false;
    }
    else{
        // it is not an empty tree
        TreeNode *current = root;
        while(current->key != value){
            if(value < current->key)
                current = current->left;
            else
                current = current->right;

            if(current == NULL) // we didn't find value
                return false;
        }
    }
    return true;
}

template<class T>
bool BST::deleteNode(int k){
    if(isEmpty()){
        return false;
    }

    TreeNode *parent = root;
    TreeNode *current = root;
    bool isLeft = true;

    while(current->key != k){
        parent = current;
        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
            return false;
    }

    // if we make it here, we found the value, now let's proceed to delete
    if(current->left == NULL && current->right == NULL){
        // then we have a leaf treenode
        if(current == root)
            root == NULL;
        else if(isLeft)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // these branching statements identify position of node to be deleted
    else if(current->right == NULL){
        // no right child, one left child
        if(current == root)
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if(current->left == NULL){
        // one right child, no left child
        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->right = current->right;
        else
            parent->left = current->right;
    }
    // the node to be deleted has two children
    else{
        TreeNode *successor = getSuccessor(current);

        if(current == root)
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;

        // connect or link successor to current's left child (d)
        successor-> left = current->left;

        return true;
    }
}

template<class T>
bool BST::isEmpty(){
    return (root == NULL);
}

template<class T>
TreeNode* BST::getMin(){
    TreeNode *curr = root;

    if(root == NULL){
        return NULL;
    }
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

template<class T>
TreeNode* BST::getMax(){
    TreeNode *curr = root;

    if(root == NULL){
        return NULL;
    }
    while(curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

template<class T>
TreeNode *BST::getSuccessor(TreeNode *d){
    // the parameter d represents the node to be deleted
    Treenode *current = d->right;
    TreeNode *sp = d;
    TreeNode *successor = d;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    // if successor is not right child of node to be deleted
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }

    return successor;
}

template<class T>
void BST::printTree(TreeNode *node){
    if(node == NULL)
        return;

    printTree(node->left);
    cout << node->key << endl;
    printTree(node->right);
}
