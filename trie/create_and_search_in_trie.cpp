# include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool is_completed;

    TrieNode() {
        this->children = unordered_map<char, TrieNode*>{};
        this->is_completed = false;
    }
};

TrieNode *root = new TrieNode();

void add() {
    vector<string> strings = {"abc", "abgl", "cdf", "abcd", "lmn"};

    for (auto s: strings) {
        TrieNode *currNode = root;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (currNode->children.count(ch) == 0) { // currNode->children.find(ch) == currNode->children.end()

                TrieNode* nextNode = new TrieNode();

                // (currNode->children).insert(make_pair(ch, nextNode));
                currNode->children[ch] = nextNode;
                currNode = nextNode;
            } else {
                currNode = currNode->children[ch];
            }

            currNode->is_completed = true;
        }
    }
}

void search() {
    vector<string> strings = {"abc", "abgl", "cdf", "abcd", "lmn", "lmno", "plw"};

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
            matches.push_back(true);
        }
    }

    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << matches[i] << endl;
    }
}

int main() {
    add();
    search();

    return 0;
}