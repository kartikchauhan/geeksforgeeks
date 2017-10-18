// construct a binary search tree using preOrder traversal. Time complexity: O(n^2)

#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
    
        Node(int key)
        {
            this->data = key;
            this->left = NULL;
            this->right = NULL;
        }    
};

// properties and methods of tree
class Tree
{        
    private:
    
        stack<Node *>s;
    
        int searchIndex(vector<int> &preOrder, int value, int first, int second)
        {   
            for(int i=first; i<=second; i++)
            {
                if(preOrder[i] > value)
                    return i;
            }
            return 0;
        }
    
    public:
    
        void inOrder(Node *root)
        {
            if(root == NULL)
                return;
            this->inOrder(root->left);
            if(root->data != -1)
                cout << root->data << " ";
            this->inOrder(root->right);
        }  
    
        void inOrderIterative(Node *root)
        {            
            while(!(this->s.empty() && root == NULL))
            {
                if(root != NULL)
                {
                    this->s.push(root);
                    root = root->left;
                }
                else
                {
                    root = this->s.top();
                    this->s.pop();
                    cout << root->data << " ";
                    root = root->right;
                }
            }
        }            
    
        Node *constructTreeUtil(vector<int> &preOrder, int first, int second)
        {
            if(first > second)
                return NULL;
                        
            Node *root = new Node(preOrder[first]);  
            if(first == second)
            {
                return root;
            }                

            int i = this->searchIndex(preOrder, root->data, first+1, second);
            
            root->left = constructTreeUtil(preOrder, first+1, i-1);
            root->right = constructTreeUtil(preOrder, i, second);
            
            return root;
        }
    
        Node *constructTree(vector<int> &preOrder)
        {
            int size = preOrder.size();
            Node *root = this->constructTreeUtil(preOrder, 0, size-1);
            return root;
        }
    
};

int main() 
{
    vector<int> preOrder;
    int a;
    while(cin >> a)
    {
        preOrder.push_back(a);
    }
    Tree tree; 
    Node *root = tree.constructTree(preOrder);
    tree.inOrder(root);
    return 0;
}

// Input: 10 5 1 7 40 50
