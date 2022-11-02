//
// Created by user on 02-Nov-22.
//

#include "Problem1.h"

#include <iostream>
#include "vector"

using namespace std;
template <class T>
struct treeNode {
    T *data;
    struct treeNode * left;
    struct treeNode * right;
};
template <class T>
struct btree {

private:
    vector< treeNode<T>*> nodeslist ;
    int parentIndex(int node){
        return (node-1)/2;
    }
    int treeSize(treeNode<T>* root){
        if (root == NULL) return 0;
        return 1 + treeSize(root->left) + treeSize(root->right);
    }
    void postOrderPrint(treeNode<T>* root){
        if (root == NULL) return;
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout << *(root->data) << " ";
    }
    void preOrderPrint(treeNode<T>* root){
        if (root == NULL) return;
        cout << *(root->data) << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
public:
    void addNode(T data){
        int *a = new int;
        *a=data;
        treeNode<T> *temp = new treeNode<T>;
        *temp = {a,NULL,NULL};
        int ind;
        for (int i = 0; i < nodeslist.size(); ++i) {
            if(nodeslist[i] == NULL){
                ind = i;
                break;
            }
            else ind = i+1;
        }
        if (ind < nodeslist.size()) nodeslist[ind] = temp;
        else nodeslist.push_back(temp);
        if (ind != 0){
            int parent = parentIndex(ind);
            if(nodeslist[parent]->left != NULL) nodeslist[parent]->right = temp;
            else nodeslist[parent]->left = temp;
        }

    }
    void deleteNode(T data){
        int ind = -1;
        for(int i = 0; i<nodeslist.size(); i++){
            if (nodeslist[i] != NULL && *(nodeslist[i]->data) == data){
                ind = i;
            }
        }
        if (ind != -1 && nodeslist[ind]->left == NULL && nodeslist[ind]->right == NULL){
            treeNode<T> *temp = nodeslist[ind];
            nodeslist[ind] = NULL;
            if (ind != 0){
                int parent = parentIndex(ind);
                if (ind%2 == 0) nodeslist[parent]->right = NULL;
                else nodeslist[parent]->left = NULL;
            }
            free(temp);
        }
        else cout<<"CANNOT DELETE NODE"<<endl;
    }
    int treeSize(){
        if (nodeslist.size() == 0) return 0;
        return treeSize(nodeslist[0]);
    }
    int subtreeSize(T data){
        int ind = -1;
        for(int i = 0; i<nodeslist.size(); i++){
            if (nodeslist[i] != NULL && *(nodeslist[i]->data) == data){
                ind = i;
            }
        }
        if (ind != -1) return treeSize(nodeslist[ind]);
        return 0;
    }
    void postOrderPrint(){
        postOrderPrint(nodeslist[0]);
    }
    void preOrderPrint(){
        preOrderPrint(nodeslist[0]);
    }
};

// Tested adding 4 nodes
// Tested treeSize function
// added 3 more nodes and printed the order of the tree, both PreOrder and PostOrder
int main() {
    btree<int> tree;
    tree.addNode(12);
    tree.addNode(51);
    tree.addNode(3);
    tree.addNode(76);
    cout << "Size of Tree: " << tree.treeSize();
    tree.addNode(25);
    tree.addNode(8);
    tree.addNode(10);
    cout << endl << "Post Order: ";
    tree.postOrderPrint();
    cout << endl << "Pre Order";
    tree.preOrderPrint();
    return 0;
}