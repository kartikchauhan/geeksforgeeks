// find the distance between two nodes of a Binary Search Tree

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

        Node *lowestCommonAncestor(Node *root, int v1, int v2)
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
                    if(curr->data >= v1 && curr->data <= v2)
                    {
                        return curr;
                    }
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            }     
            return root;
        }

        int calcDistance(Node *root, int value)
        {
            int dis = 0;
            while(root->data != value)
            {
                if(value < root->data)
                {
                    dis++;
                    root = root->left;
                }
                else if(value > root->data)
                {
                    dis++;
                    root = root->right;
                }
            }

            return dis;
        }

    public:

        void insert(Node *root, int data)
        {
            Node *curr = new Node(data);    // first step in Insertion procedure is to create the Node with the given data
            curr = this->insertNode(root, curr);
        }    
        
        int findDistance(Node *root, int first, int second)
        {
            Node *lca = this->lowestCommonAncestor(root, first, second);
            
            int leftDis = this->calcDistance(lca, first);
            int rightDis = this->calcDistance(lca, second);
            return (leftDis + rightDis);
        }
        
};

int main() 
{
    int num;
    cin >> num;

    int first, second;
    cin >> first >> second;

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
    
    if(first > second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    
    cout << bt.findDistance(root, first, second) << endl;
    
    return 0;
}

//Input:
10
6 21
20 8 22 4 6 12 10 14 21 24