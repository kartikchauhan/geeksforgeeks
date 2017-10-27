// find the maximum element between two nodes of BST

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
    
        Node *lca(Node *root, int start, int end)
        {
            queue<Node *> q;
            q.push(root);
            
            while(q.size())
            {
                int q_size = q.size();
                while(q_size--)
                {
                    Node *curr = q.front();
                    q.pop();
                    if(curr->data >= start && curr->data <= end)
                        return curr;

                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            }     
            return root;
        }
    
        int maxValue(Node *root)
        {
            if(root == NULL)
                return -1;
            
            while(root->right != NULL)
                root = root->right;
            
            return root->data;
        }

    public:

        void insert(Node *root, int data)
        {
            Node *curr = new Node(data);    // first step in Insertion procedure is to create the Node with the given data
            curr = this->insertNode(root, curr);
        }    
    
        int maxElement(Node *root, int start, int end)
        {
            Node *lcaNode = this->lca(root, start, end);
            return this->maxValue(lcaNode);
        }

};

int main() 
{
    int num, start, end;
    cin >> num;
    cin >> start >> end;

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
    
    cout << bt.maxElement(root, start, end) << endl;
    
    return 0;
}

// Input:
9
4 10
20 8 22 4 12 10 14 21 24