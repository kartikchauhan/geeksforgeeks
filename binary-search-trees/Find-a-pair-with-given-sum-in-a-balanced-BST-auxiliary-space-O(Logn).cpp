// Find a pair with given sum in a Balanced BST. Constraints: Auxiliary space: O(Logn), Time complexity: O(n)

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
        stack<Node *> s1, s2;
    
    public:
        bool checkSumExists(Node *root, int sum)
        {
            Node *temp = root;
            
            // push all left elements
            while(temp->data != -1)
            {
                this->s1.push(temp);
                temp = temp->left;
            }
            
            // push all right elements
            temp = root;
            while(temp->data != -1)
            {
                this->s2.push(temp);
                temp = temp->right;
            }
            
            // run the loop until both stack get empty or we reach into the left subtree value beccomes greater than right subtree
            while((!this->s1.empty() || !this->s2.empty()) && (this->s1.top()->data < this->s2.top()->data))
            {
                if((this->s1.top()->data + this->s2.top()->data) == sum)
                {
                    cout << this->s1.top()->data << " " << this->s2.top()->data << endl;
                    return true;
                }
                // if s1.top + s2.top > sum, it means we need to mitigate the value, so we pop the top element from s2 in search of a smaller value & we successively push all the value in that subtree
                else if((this->s1.top()->data + this->s2.top()->data) > sum)
                {
                    temp = this->s2.top();
                    this->s2.pop();
                    if(temp->left->data != -1)
                    {
                        temp = temp->left;
                        while(temp->data != -1)
                        {
                            this->s2.push(temp);
                            temp = temp->right;
                        }
                    }
                }
                // if s1.top + s2.top < sum, it means we need to increase the value, so we pop the top element from s1 in search of a greater value & we successively push all the value in that subtree
                else if((this->s1.top()->data + this->s2.top()->data) < sum)
                {
                    temp = this->s1.top();
                    this->s1.pop();
                    if(temp->right->data != -1)
                    {
                        temp = temp->right;
                        while(temp->data != -1)
                        {
                            this->s1.push(temp);
                            temp = temp->left;
                        }
                    }
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