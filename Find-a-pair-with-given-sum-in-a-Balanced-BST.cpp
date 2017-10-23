// Find a pair with given sum in a Balanced BST. Constraints: Auxiliary space: O(n), Time complexity: O(n)

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

class TNode
{
    public:
        bool isBST;
        int size, min, max;
    
        TNode(bool isBST, int size, int min, int max)
        {
            this->isBST = isBST;
            this->size = size;
            this->min = min;
            this->max = max;
        }
};

// properties and methods of tree
class Tree
{        
    private:
        vector<int> sortedVector;
    
    public:
        void inOrder(Node *root)
        {
            if(root == NULL)
                return;
            this->inOrder(root->left);
            if(root->data != -1)
                sortedVector.push_back(root->data);
            this->inOrder(root->right);
        }   
    
        bool checkSumExists(Node *root, int sum)
        {
            this->inOrder(root);
            
            int size = this->sortedVector.size();
            int begin = 0, end = size-1;
            while(begin < end)
            {
                if((this->sortedVector[begin] + this->sortedVector[end]) == sum)
                {
                    cout << sortedVector[begin] << " " << this->sortedVector[end] << endl;
                    return true;
                }
                else if((this->sortedVector[begin] + this->sortedVector[end]) > sum)
                {
                    end--;
                }
                else if((this->sortedVector[begin] + this->sortedVector[end]) < sum) 
                {
                    begin++;
                }
            }
            return false;
        }
};

int main() 
{
    // creation of tree starts here
    queue<Node *> q;
    
    int sum;
    cin >> sum;
    
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
    tree.checkSumExists(root, sum) ? cout << "Sum exists" : cout << "Sum doesn't exists";
}

// Input:
156
50
30 100
18 31
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