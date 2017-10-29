// construct a balanced binary search tree from a sorted linked list. Time complexity: O(n)

#include <bits/stdc++.h>

using namespace std;

class LNode
{
    public:
        int data;
        LNode *next;
    
        LNode(int key)
        {
            this->data = key;
            this->next = NULL;
        }
};

class LinkedList
{
    public:
        LNode *create(vector<int> &list)
        {
            int size = list.size();
            LNode *head = NULL, *prev = NULL, *curr = NULL;
            for(int i=0; i<size; i++)
            {
                curr = new LNode(list[i]);
                if(head == NULL)
                    head = curr;
                if(prev == NULL)
                {
                    prev = curr;
                }
                else
                {
                    prev->next = curr;
                    prev = curr;
                }
            }
            return head;
        }
};

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
    
        Node *create(LNode **head, int size)
        {
            if(size <= 0)   
                return NULL;
            
            Node *left = this->create(head, size/2);
            
            Node *root = new Node((*head)->data);
            root->left = left;
            
            (*head) = (*head)->next;
            
            root->right = this->create(head, size-(size/2)-1);
            
            return root;
        }
          
};

int main() 
{
    vector<int> list;
    int a;
    while(cin >> a)
        list.push_back(a);  // get all the elements in the list
    
    sort(list.begin(), list.end());   // sort the elements before creating linked list
    
    LinkedList linkedList;
    LNode *head = linkedList.create(list);  //create linked list of sorted elements

    LNode *temp = head;
    
    Tree tree;
    Node *root = tree.create(&head, list.size());
    
    tree.inOrder(root);
    return 0;
}

// Input: 2 4 6 3 5 1