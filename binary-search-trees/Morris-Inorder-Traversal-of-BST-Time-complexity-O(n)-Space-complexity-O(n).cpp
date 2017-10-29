// Morris Inorder Traversal of a BST. Time complexity: O(n). Space complexity: O(1)

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

        Node *inOrderPredecessor(Node *root)
        {
            Node *curr = root->left;
            
            while(!(curr->right == NULL || curr->right == root))
                curr = curr->right;

            return curr;
        }
    

    public:

        void insert(Node *root, int data)
        {
            Node *curr = new Node(data);    // first step in Insertion procedure is to create the Node with the given data
            curr = this->insertNode(root, curr);
        }    
    
        void morrisInorderTraversal(Node *root)
        {
            while(root != NULL)
            {
                if(root->left == NULL)
                {
                    cout << root->data << " ";
                    root = root->right;
                }
                else
                {
                    Node *predecessor = this->inOrderPredecessor(root);
                    if(predecessor->right == NULL)
                    {
                        predecessor->right = root;
                        root = root->left;
                    }
                    else if(predecessor->right == root)
                    {
                        predecessor->right = NULL;
                        cout << root->data << " ";
                        root = root->right;
                    }
                }
            }
        }

};

int main() 
{
    int num;
    cin >> num;

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
    
    bt.morrisInorderTraversal(root);
    
    return 0;
}

// Input:
9
20 8 22 4 12 10 14 21 24