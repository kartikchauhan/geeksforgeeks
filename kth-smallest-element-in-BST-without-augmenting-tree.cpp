// find the kth smallest element in a binary search tree. No augmentation.

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
    
        Node *kthSmallest(Node *root, int k)
        {
            int numLeftChildren = numNodes(root->left);
            if(numLeftChildren+1 == k)
            {
                return root;
            }
            else if(numLeftChildren >= k)
            {
                return kthSmallest(root->left, k);
            }
            else if(numLeftChildren < k)
            {
                return kthSmallest(root->right, k-(numLeftChildren+1));
            }
            return root;    // hackerrank's return type constraint
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
            if(root == NULL)
                return 0;
            
            queue<Node *> q;
            q.push(root);
            int sum = 0;

            while(q.size())
            {
                int q_size = q.size();
                while(q_size--)
                {
                    Node *curr = q.front();
                    q.pop();
                    sum++;
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            } 
            return sum;
        }
};

int main() 
{
    int num, k;
    cin >> num >> k;

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
    
    cout << bt.kthSmallest(root, k)->data;
    return 0;
}

// Input: 
9 5
20 8 22 4 12 10 14 21 24