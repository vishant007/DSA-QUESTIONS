#include <iostream>
#include <queue>
 
using namespace std;
 
// tree class
class Node
{
public:
    int data;
    Node* left;
    Node* right;
 
    Node(int data): data(data), left(NULL), right(NULL) {}
};
 

Node* build_preorder()
{
    // input an element
    int ele;
    cin >> ele;
 
    // base case
    if(ele == -1)
        return NULL;
     
    // first insert the data
    // into the root
    Node* root = new Node(ele);
 
    // now build the left subtree
    root->left = build_preorder();
 
    // similarly the right subtree
    root->right = build_preorder();
 
    // finally return the root
    return root;
}
 
// Breadth-First Search Algorithm
void BFS(Node* root)
{
    cout << "The BFS traversal of the tree is:" << endl;
 
    // queue to store the nodes
    queue <Node*> q;
 
    // pushing root and NULL into the queue
    q.push(root);
    q.push(NULL);
 

    while(!q.empty())
    {
        
        Node *f = q.front();
 
       
        q.pop();
 
        if(f == NULL)
        {
          
            cout << endl;
 
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            
            cout << f->data << " ";
             
          
            if(f->left)
                q.push(f->left);
             
           
            if(f->right)
                q.push(f->right);
        }
    }
}
 

int main()
{
    cout << "Enter the elements of the tree in pre-order manner" << endl;
     
   
    Node *root = build_preorder();
 
    BFS(root);
}