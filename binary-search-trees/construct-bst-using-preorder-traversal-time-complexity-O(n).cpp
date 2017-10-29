// construct a binary search tree using preOrder traversal. Time complexity: O(n)

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
    
        Node *constructTreeUtil(vector<int> &preOrder, int &preIndex, int val, int min, int max, int size)
        {
            if(preIndex >= size)
                return NULL;
            
            Node *root = NULL;
            
            if(val > min && val < max)
            {
                root = new Node(val);
                preIndex += 1;
                
                if(preIndex < size)
                {
                    root->left = constructTreeUtil(preOrder, preIndex, preOrder[preIndex], min, val, size);
                    root->right = constructTreeUtil(preOrder, preIndex, preOrder[preIndex], val, max, size);
                }                
            }
            return root;
        }
    
        Node *constructTree(vector<int> &preOrder)
        {
            int size = preOrder.size();
            int preIndex = 0;
            Node *root = this->constructTreeUtil(preOrder, preIndex, preOrder[0], -1000, 1000, size);
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