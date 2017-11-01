// creation and searching of an element in Trie data structure

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Node
{
    public:
        map<char, Node *> children;
        bool isEnd;

        Node()
        {
            this->isEnd = false;
        }
};

class Trie
{
    private:
        bool exists(Node* &curr, char c)
        {
            if(curr->children.size() != 0 && curr->children.find(c) != curr->children.end())	// the condition checks if the character exists  in the current map or not
                return true;
            return false;
        }

    public:
        void create(vector<string> &input, Node* &root)
        {
            Node *curr = root;
            int numStrings = input.size();

            for(int i=0; i<numStrings; i++)
            {
                int currStringSize = input[i].length();

                for(int j=0; j<currStringSize; j++)
                {
                    char c = input[i][j];
                    if(this->exists(curr, c))
                    {
                        curr = curr->children[c];
                    }
                    else
                    {
                        Node *temp = new Node();
                        curr->children[c] = temp;
                        curr = temp;
                        if(j == currStringSize - 1)	// if last element of the string, then end the branch
                            curr->isEnd = true;
                    }
                }

                curr = root;
            }
        }	

        bool search(Node * &root, string s)
        {
        	int length = s.length();        	
        	Node *curr = root;

        	for(int i=0; i<length; i++)
        	{
        		char c = s[i];
        		if(this->exists(curr, c))
        			curr = curr->children[c];
        		else
        			return false;
        	}
        	if(curr->isEnd == true)
        		return true;
            else
                return false;                                
        }
};

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> input(n);

	for(int i=0; i<n; i++)
		cin >> input[i];

	Node *root = new Node();

	Trie tree;
	tree.create(input, root);

	int q;
	cin >> q;

	string s;
	for(int i=0; i<q; i++)
	{
		cin >> s;
		tree.search(root, s) ? cout << "yes" : cout << "no";
        cout << '\n';
	}
    return 0;
}

// Input:
5
abc
abgl
cdf
abcd
lmn
2
lmnf
abcl