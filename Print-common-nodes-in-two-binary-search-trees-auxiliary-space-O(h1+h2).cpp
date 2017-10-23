// Print Common Nodes in Two Binary Search Trees. Auixiliary space: O(h1+h2), Time complexity: O(n)

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
        stack<Node *> s1, s2;
    
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
    
        void printCommonNodes(Node *root1, Node *root2)
        {
            Node *temp = root1;
            
            // push all left child elements in s1
            while(temp->data != -1)
            {
                this->s1.push(temp);
                temp = temp->left;
            }
            
            temp = root2;

            // push all left child elements in s2
            while(temp->data != -1)
            {
                this->s2.push(temp);
                temp = temp->left;
            }
            
            while(!this->s1.empty() && !this->s2.empty())
            {
                if(this->s1.top()->data == this->s2.top()->data)
                {
                    cout << this->s1.top()->data << " ";
                }
                else if(this->s1.top()->data > this->s2.top()->data)
                {
                    temp = this->s2.top();
                    this->s2.pop();
                    if(temp->right->data != -1)
                    {
                        temp = temp->right;
                        while(temp->data != -1)
                        {
                            this->s2.push(temp);
                            temp = temp->left;
                        }
                    }
                }
                else if(this->s1.top()->data < this->s2.top()->data)
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
        }
};

int main() 
{
    queue<Node *> q;
    
    int rootVal;
    cin >> rootVal;
    
    Node *root = new Node(rootVal);
    q.push(root);
    
    string line;
    int a, b;
    while(getline(cin, line))
    {
        istringstream is(line);
        while(is >> a >> b)
        {
            cout << a << " " << b << endl;
        //     Node * curr = q.front();
        //     q.pop();
            
        //     Node *temp = new Node(a);
        //     curr->left = temp;
        //     if(temp->data != -1)
        //         q.push(temp);
            
        //     temp = new Node(b);
        //     curr->right = temp;
        //     if(temp->data != -1)
        //         q.push(temp);
        // }  
    }
    
    // Tree tree;
    // tree.inOrder(root);
    
    
    
    // creation of first tree starts here
    
    // int rootVal;
    // cin >> rootVal;
    
    
    // int a, b;
    // while(cin >> a >> b)
    // {
    //     
    // }
    // // creation of tree ends here
    
    // Tree tree;
    // tree.printCommonNodes(root1, root2);
}
