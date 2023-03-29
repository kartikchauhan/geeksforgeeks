// https://takeuforward.org/data-structure/word-search-ii/

#include <bits/stdc++.h>

using namespace std;

bool searchElement(vector< vector<char> > &grid, string s, int rows, int cols, int j, int k, int i) {

    // cout << " j " << j << " k " << k << " i " << i << endl;

    // Guard clauses or tail conditions

    if (s.length() == i) return true;

    if (j >= rows) return false;

    if (j < 0) return false;

    if (k >= cols) return false;

    if (k < 0) return false;

    if (grid[j][k] != s[i]) return false;

    if (grid[j][k] == '$') return false;
    
    grid[j][k] = '$';

    // cout << "Character matched " << s[i] << endl;

    // search for next element in adjacent positions

    bool matchFound =   searchElement(grid, s, rows, cols, j, k+1, i+1) || // right 
                        searchElement(grid, s, rows, cols, j+1, k, i+1) || // down
                        searchElement(grid, s, rows, cols, j, k-1, i+1) || // left
                        searchElement(grid, s, rows, cols, j-1, k, i+1);    // up

    grid[j][k] = s[i];

    return matchFound;
}

int main() {
    int rows = 4;
    int cols = 4;

    vector< vector<char> > grid(rows, vector<char>(cols));

    grid[0] = {'b', 'a', 'l', 'g'};
    grid[1] = {'g', 'd', 'a', 'f'};
    grid[2] = {'h', 'b', 'm', 'o'};
    grid[3] = {'y', 'z', 'o', 'm'};

    vector<string> words = { "mom", "elephant", "bob", "badam", "glad" };

    // using DFS

    for (auto s : words) {
        cout << "searching " << s << endl;

        int i = 0;

        // iterate over grid elements

        for (int j = 0; j < rows; j++) {

            for (int k = 0; k < cols; k++) {

                bool matchFound = searchElement(grid, s, rows, cols, j, k, i);

                if (matchFound) {
                    cout << "Found " << s << endl;
                }
            }
        }
    }
}