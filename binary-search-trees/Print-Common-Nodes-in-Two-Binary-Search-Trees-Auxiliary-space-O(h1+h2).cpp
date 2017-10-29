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
    
        void insertLeftSubTree(Node *temp, stack<Node *> &s)
        {
            while(temp->data != -1)
            {
                s.push(temp);
                temp = temp->left;
            }
        }

        void insertRightSubTree(stack<Node *> &s)
        {
            Node *temp = s.top();
            s.pop();
            if(temp->right->data != -1)
            {
                temp = temp->right;
                while(temp->data != -1)
                {
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
    
    public:
    
        void printCommonNodes(Node *root1, Node *root2)
        {
            stack<Node *> s1, s2;
            
            this->insertLeftSubTree(root1, s1);     // push all the left children into the stack s1
            this->insertLeftSubTree(root2, s2);     // push all the left children into the stack s2
            
            while(!s1.empty() && !s2.empty())
            {
                if(s1.top()->data == s2.top()->data)
                {
                    cout << s1.top()->data << " ";  // print the element if s1.top == s2.top
                    this->insertRightSubTree(s1);   // pop the top element from s1 and push right child
                    this->insertRightSubTree(s2);   // pop the top element from s2 and push right child
                }
                else if(s1.top()->data > s2.top()->data)
                {
                    this->insertRightSubTree(s2);   // pop the top element from s2 and push right child
                }
                else if(s1.top()->data < s2.top()->data)
                {
                    this->insertRightSubTree(s1);   // pop the top element from s1 and push right child
                }
            }
        }
};

int main() 
{
    queue<Node *> q;
    Node *root1, *root2;
    
    int counter = 0;
    string line;
    int a, b;

    // get the input
    for(int i=0; i<2; i++)
    {
        while(getline(cin, line))
        {                    
            if(line.length() == 0)  // if enounters an empty line, stop taking inputs
                break;

            istringstream numbers(line);    // read the string stream into numbers
            if(++counter == 1)  // counter == 1, means taking root value as input
            {
                if(numbers >> a)
                {
                    if(i == 0)
                    {
                        root1 = new Node(a);
                        q.push(root1);     
                    }
                    else if(i == 1)
                    {
                        root2 = new Node(a);
                        q.push(root2); 
                    }
                }
            }
            else
            {
                if(numbers >> a >> b)
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
            }
        }
        counter = 0;
    }
    
    Tree tree;
    tree.printCommonNodes(root1, root2);
}
// Input:
50
30 60
10 40
55 75
-1 -1
-1 -1
-1 -1
-1 -1

30
10 40
5 15
35 45
-1 -1
-1 -1
-1 -1
-1 -1