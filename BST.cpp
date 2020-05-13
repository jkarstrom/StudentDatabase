//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "BST.h"

template<class T>
BST<T>::BST(){
}

template<class T>
BST<T>::~BST(){

}

template<class T>
void BST<T>::insert(int id, T* value){
    TreeNode<T> *node = new TreeNode<T>(id, value);

    if(isEmpty()){
        // empty tree
        root = node;
    }
    else{
        // not an empty tree
        TreeNode<T> *curr = root; // start at the root
        TreeNode<T> *parent;

        while(true){
            parent = curr;
            if(id < curr->key){
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
bool BST<T>::search(int id, int action, T* soul){
    if(isEmpty()){
        cout << "Please add people to your database first." << endl;
        return false;
    }
    else{
        // it is not an empty tree
        TreeNode<T> *current = root;
        while(current->key != id){

            if(id < current->key)
                current = current->left;
            else
                current = current->right;

            if(current == NULL) // we didn't find value
                cout << "ID not in database. Please try again." << endl;
                return false;
        }
        // ASSIGNMENT SPECIFIC CODE ----------------------------------------------------

        if(action == 3 || action == 4){
            current->value->printInfo();}
        else if(action == 5 || action == 6)
            current->value->printAd();
        else if(action >= 7 && action <= 10)
            current->value->transfer(soul);

    }
    return true;
}

template<class T>
bool BST<T>::deleteNode(int k){
    if(isEmpty()){
        return false;
    }

    TreeNode<T> *parent = root;
    TreeNode<T> *current = root;
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
            root = NULL;
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
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root)
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else
            parent->right = successor;

        // connect or link successor to current's left child (d)
        successor-> left = current->left;
    }
    return true;
}

template<class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template<class T>
TreeNode<T>* BST<T>::getMin(){
    TreeNode<T>*curr = root;

    if(root == NULL){
        return NULL;
    }
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

template<class T>
TreeNode<T>* BST<T>::getMax(){
    TreeNode<T>*curr = root;

    if(root == NULL){
        return NULL;
    }
    while(curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d){
    // the parameter d represents the node to be deleted
    TreeNode<T>* current = d->right;
    TreeNode<T>* sp = d;
    TreeNode<T>* successor = d;

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
void BST<T>::printTree(TreeNode<T> *d){
    TreeNode<T>* node = d;

    if(node == NULL){}

    else{
        printTree(node->left);
        node->value->printInfo(); // PRINT INFO HERE -----------------------------
        printTree(node->right);
    }
}

template<class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}

template class BST<Faculty>;
template class BST<Student>;
