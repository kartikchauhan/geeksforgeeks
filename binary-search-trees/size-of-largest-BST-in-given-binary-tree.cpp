// Given a binary tree, return the size of the largest subtree which is also a binary search tree.
// The program might provide unexpected results if there's duplicate entries of an item/value.

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
        int max(int a, int b)
        {
            return a > b ? a : b;
        }
    
        TNode *largestBST(Node *root)
        {
            if(root->data == -1)
            {
                return NULL;
            }
            
            TNode *lst = largestBST(root->left);
            TNode *rst = largestBST(root->right);
            
            if(lst == NULL && rst == NULL)
            {
                TNode *temp = new TNode(true, 1, root->data, root->data);
                return temp;
            }
            else if(lst == NULL && rst != NULL)
            {
                if(root->data < rst->min && rst->isBST != false)
                {
                    TNode *temp = new TNode(true, rst->size+1, root->data, rst->max);
                    return temp;
                }
                else
                {
                    TNode *temp = new TNode(false, rst->size, 0, 0);
                    return temp;
                }
            }
            else if(rst == NULL && lst != NULL)
            {
                if(root->data > lst->max && lst->isBST != false)
                {
                    TNode *temp = new TNode(true, lst->size+1, lst->min, root->data);
                    return temp;
                }
                else
                {
                    TNode *temp = new TNode(false, lst->size, 0, 0);
                    return temp;
                }
            }
            else if(lst != NULL && rst != NULL)
            {
                if((root->data > lst->max && root->data < rst->min) && (lst->isBST != false && rst->isBST != false))
                {
                    TNode *temp = new TNode(true, lst->size+rst->size+1, lst->min, rst->max);
                    return temp;
                }
                else
                {
                    TNode *temp = new TNode(false, this->max(lst->size, rst->size), 0, 0);
                    return temp;
                }    
            }
            TNode *temp = new TNode(true, 0, 0, 0);
            return temp;
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
    
        int largestBSTUtil(Node *root)
        {
            TNode *curr = this->largestBST(root);
            return curr->size;
        }
};

int main() 
{
    // creation of tree starts here
    queue<Node *> q;
    
    int rootVal;
    cin >> rootVal;
    Node *root = new Node(rootVal);
    q.push(root);
    
    int a, b;
    while(cin >> a >> b)
    {
        Node * curr = q.front();
        q.pop();
        
        Node *temp = new Node(a);
        curr->left = temp;
        if(temp->data != -1)
            q.push(temp);
        
        temp = new Node(b);
        curr->right = temp;
        if(temp->data != -1)
            q.push(temp);
    }
    // creation of tree ends here
    
    Tree tree;
    cout << tree.largestBSTUtil(root);
}

// Input:
50
31 100
18 30
75 125
-1 -1
-1 35
70 80
120 130
-1 -1
-1 -1
-1 -1
-1 -1
-1 -1