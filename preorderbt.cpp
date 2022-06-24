#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}

Node* constructBT(int preorder[], int*  preorderIdx, int key, int min,int max, int n){
    
    if(*preorderIdx >= n){
        return NULL;
    }
    
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preorderIdx = *preorderIdx +1; 

    if(preorderIdx < n){
        root->left = constructBT(preorder, preorderIdx, preorder[*preorderIdx], min, key, n)        
    }

    if(*preorderIdx < n){
        root->right = constructBT(preorder, preorderIdx, preorder[*preorderIdx], key, max, n)
    }

    }
    return root;

}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
}

int main(){
 
    int preorder[] = {10, 2, 1, 13, 12};
    int n = 5;
    int preorderIdx = 0;
    constructBT(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    return 0;

}