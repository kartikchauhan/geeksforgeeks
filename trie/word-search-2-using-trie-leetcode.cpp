// https://leetcode.com/problems/word-search-ii/description/

#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool is_completed;
        string str;

    TrieNode() {
        this->children = unordered_map<char, TrieNode*>{};
        this->is_completed = false;
        this->str = "";
    }

    bool containsKey(char c) {
        return this->children.count(c) && 1;
    }

    void add(char c) {
        this->children[c] = new TrieNode();
    }

    TrieNode* get(char c) {
        return this->children[c];
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode *root = createTrie(words);

        searchInTrie(words, root);
        
        unordered_set<string> st;

        int rows = board.size();
        int cols = board[0].size();


        // iterate over grid elements

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                TrieNode * curr = root;

                search(board, st, root, rows, cols, i, j);

                // cout << "back to sqaure 1" << endl;
            }
        }

        vector<string> vc(st.begin(), st.end());

        return vc;
    }


void searchInTrie(vector<string> & strings, TrieNode *root) {

    vector<bool> matches;

    for (auto s: strings) {
        TrieNode *currNode = root;

        bool isFound = true;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (currNode->children.count(ch) == 0) { // currNode->children.find(ch) == currNode->children.end()
                isFound = false;
                break;
            } else {
                currNode = currNode->children[ch];
            }
        }

        if (currNode->is_completed == false || isFound == false) {
                matches.push_back(false);
        } else {
            // cout << "currNode->str " << currNode->str << endl;
            matches.push_back(true);
        }
    }

    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << matches[i] << endl;
    }
}

    TrieNode* createTrie(vector<string> & words) {
        TrieNode* root = new TrieNode();

        for (auto w : words) {

            TrieNode *curr = root;

            for (int i = 0; i < w.length(); i++) {
                char c = w[i];

                if (! curr->containsKey(c)) {
                    curr->add(c);
                    curr = curr->get(c);
                } else {
                    curr = curr->get(c);
                }
            }

            curr->is_completed = true;
            curr->str = w;
        }

        return root;
    }

    bool search(vector<vector<char>>& grid, unordered_set<string> &st, TrieNode* root, int rows, int cols, int i, int j) {
        // cout << " i " << i << " j " << j << endl;
        
        if (root->is_completed == true) {
            // cout << "root->is_completed" << endl;
            st.insert(root->str);

            // for (auto s : st) {
            //     cout << "set element " << s << endl;
            // }
        }

        if (i >= rows) return false;

        if (i < 0) return false;

        if (j >= cols) return false;

        if (j < 0) return false;

        if (grid[i][j] == '$') return false;

        char c = grid[i][j];

        // cout << "Searching " << c << endl;

        if(! root->containsKey(c)) return false;

        grid[i][j] = '$';

        // cout << c << " exists" << endl;

        TrieNode *nextNode = root->get(c);

        bool found = search(grid, st, nextNode, rows, cols, i+1, j) || // down
                    search(grid, st, nextNode, rows, cols, i-1, j) || // up
                    search(grid, st, nextNode, rows, cols, i, j+1) || // right
                    search(grid, st, nextNode, rows, cols, i, j-1); // left

        // cout << "found " << found << endl;
        
        grid[i][j] = c;

        return found;
    }
};