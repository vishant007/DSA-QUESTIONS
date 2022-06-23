#include <bits/stdc++.h>
using namespace std;
// class representing node of a binary tree
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};
// function to create a new node with data d
Node* newNode(int d) {
    Node *node = new Node(d);
    return node;
}
int maxLevelSum(Node *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    
    // create a queue and push root to it
    queue<Node*> q;
    q.push(root);
    // initialize maxSum as negative infinity
    int maxSum = INT_MIN;
    
    // while queue is not empty
    while (!q.empty()) {
        // At this moment the queue contains one level in it
        // initialize size as size of queue
        int size = q.size();
        // initialize sum as 0, this represents the sum of a level
        int sum = 0;
        
        // run a loop from 0 to size
        for (int i = 0; i < size; i++) {
            // remove an element from queue
            Node *curr = q.front();
            q.pop();
            // add the value of current element to sum
            sum += curr->data;
            
            // push the children of current element to queue
            if (curr->left != NULL)
                q.push(curr->left);
                
            if (curr->right != NULL)
                q.push(curr->right);
        }
        
        // update max sum
        maxSum = std::max(maxSum, sum);
    }
    
    // return max sum
    return maxSum;
}
int main() {
    // Example tree
    Node *root = newNode(5);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(11);
    root->right->left = newNode(-5);
    root->right->right = newNode(1);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(-3);
    
    cout<<maxLevelSum(root)<<endl;
    
    return 0;
}