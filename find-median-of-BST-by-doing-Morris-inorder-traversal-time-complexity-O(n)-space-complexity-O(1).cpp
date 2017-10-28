// Find the median of a BST by doing Morris Inorder Traversal. Time complexity: O(n). Space complexity: O(1)

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

        void modifiedMorrisInorderTraversal(Node *root, Node* &targetNode1, Node* &targetNode2, int &numNodes, int &count)
        {
            while(root != NULL)
            {
                if(root->left == NULL)
                {
                    count++;
                    if(count == numNodes)
                    {
                        numNodes++;
                        if(targetNode1 == NULL)
                            targetNode1 = root;
                        else if(targetNode2 == NULL)
                            targetNode2 = root;
                    }

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
                        count++;
                        if(count == numNodes)
                        {
                            numNodes++;
                            if(targetNode1 == NULL)
                                targetNode1 = root;
                            else if(targetNode2 == NULL)
                                targetNode2 = root;
                        }

                        root = root->right;
                    }
                }
            }
        }

    

    public:

        void insert(Node *root, int data)
        {
            Node *curr = new Node(data);    // first step in Insertion procedure is to create the Node with the given data
            curr = this->insertNode(root, curr);
        }    
        
        int findMedian(Node *root)
        {
            Node *medianNode1 = NULL, *medianNode2 = NULL;
            int numNodes = 0, max = numeric_limits<int>::max();

            this->modifiedMorrisInorderTraversal(root, medianNode1, medianNode2, max, numNodes);  // passing max here as an argument to keep the code short. It won't be used in the first Morris traversal.
            
            int count = 0, median;

            if(numNodes & 1)
            {
                median = (numNodes+1)/2;
                this->modifiedMorrisInorderTraversal(root, medianNode1, medianNode2, median, count);      
                return medianNode1->data;    
            }
            else
            {
                median = numNodes/2;
                this->modifiedMorrisInorderTraversal(root, medianNode1, medianNode2, median, count);          
                return (medianNode1->data + medianNode2->data) / 2;
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
    
    cout << bt.findMedian(root) << endl;
    
    return 0;
}

// Input:
8
20 8 22 4 12 10 14 21