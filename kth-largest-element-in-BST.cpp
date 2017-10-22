// find the kth largest element in a binary search tree

#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        Node *right, *left;
        int data;
    
        Node(int data)
        {
            this->right = NULL;
            this->left  = NULL;
            this->data = data;
        }
};

class BinaryTree
{
    public:

        void insert(Node *root, int data)
        {
            Node *curr = new Node(data);    // first step in Insertion procedure is to create the Node with the given data
            curr = this->insertNode(root, curr);
        }
    
        void inOrder(Node *root)
        {
            if(root == NULL)
                return;
            this->inOrder(root->left);
            if(root->data != -1)
                cout << root->data << " ";
            this->inOrder(root->right);
        }
    
        Node *kthLargest(Node *root)
        {
            if(root == NULL)
                return root;
            if(numLeftChildren(root))
        }

    private:
        
        Node* insertNode(Node *root, Node *curr)
        {
            if(root == NULL)
            {
                root = curr;
                return root;
            }
            if(curr->data < root->data)
            {
                root->left = this->insertNode(root->left, curr);
            }
            else if(curr->data > root->data)
            {
                root->right = this->insertNode(root->right, curr);
            }
            return root;
        }  
    
        int numNodes(Node *root) 
        {
            queue<Node *> q;
            q.push(root);
            int sum = 0;

            while(q.size())
            {
                int q_size = q.size();
                while(q_size--)
                {
                    node *curr = q.front();
                    q.pop();
                    summ++;
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            } 
            return summ;
        }
};

int main() 
{
    int num, k;
    cin >> num >> k;
    // Node root;
    // root = NULL;
    Node *root = NULL;
    BinaryTree bt;

    for(int i=0; i<num; i++)
    {
        int data;
        cin >> data;
        if(root == NULL)
        {
            root = new Node(data);
        }
        else
        {
            bt.insert(root, data);
        }        
    }    
    return 0;
}