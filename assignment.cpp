// Name: Nitu
// UID: 22BCS10707
// Section: 631-B


// Generae numbers with given sum :


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NumberGenerator {
public:
    vector<string> generateNumbers(int n, int sum) {
        vector<string> result;
        string current;
        generateHelper(n, sum, 0, current, result);
        return result;
    }

private:
    void generateHelper(int n, int sum, int pos, string &current, vector<string> &result) {
        if (pos == n) {
            if (sum == 0) {
                result.push_back(current);
            }
            return;
        }

        for (int digit = 0; digit <= 9; ++digit) {
            if (sum >= digit) {
                current.push_back('0' + digit);
                generateHelper(n, sum - digit, pos + 1, current, result);
                current.pop_back();
            }
        }
    }
};

int main() {
    NumberGenerator generator;
    int n, sum;
    cin >> n >> sum;

    vector<string> numbers = generator.generateNumbers(n, sum);
    for (const string &num : numbers) {
        cout << num << endl;
    }

    return 0;
}

//Binary Tree Paths:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, string path, vector<string> &result) {
        if (root == NULL)
            return;

        if (!path.empty())
            path += "->";
        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }

        inorder(root->left, path, result);
        inorder(root->right, path, result);
    }    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        inorder(root, "", result);
        return result;
    }
};


// Combinations:

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> comb;

        backtrack(1, comb, res, n, k);
        return res;        
    }

private:
    void backtrack(int start, std::vector<int>& comb, std::vector<std::vector<int>>& res, int n, int k) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int num = start; num <= n; num++) {
            comb.push_back(num);
            backtrack(num + 1, comb, res, n, k);
            comb.pop_back();
        }
    }    
};


// N-Queens II:

class Solution {
public:
    void solve(int col, int &ans, vector<int> &lrow, vector<int> &ud, vector<int> &ld, int n) {
        if (col == n) {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (lrow[row] == -1 && ud[row - col + n - 1] == -1 && ld[row + col] == -1) {
                lrow[row] = 1;
                ud[row - col + n - 1] = 1;
                ld[row + col] = 1;
                solve(col + 1, ans, lrow, ud, ld, n);
                lrow[row] = -1;
                ud[row - col + n - 1] = -1;
                ld[row + col] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<int> lrow(n, -1), ud(2 * n, -1), ld(2 * n, -1);
        solve(0, ans, lrow, ud, ld, n);
        return ans;
    }
};


// Word Ladder II:

lass Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> dist;
        unordered_map<string,vector<string>> parent;
        
   
        queue<string> q;
        q.push(beginWord);
        
        for(auto it: wordList)
        {
            dist[it] = INT_MAX; 
        }
        dist[beginWord] = 0; 

        while(!q.empty()){

            string word =q.front();q.pop();

            for(int i=0;i<word.size();i++){                
                for(char c ='a';c<='z';c++){                    
                    string nxtword = word;
                    nxtword[i]=c;    

                    if(dist.find(nxtword)!=dist.end()){ 
                        
                        if(dist[nxtword]> dist[word]+1){  
                            dist[nxtword] = dist[word]+1;
                            q.push(nxtword);
                            parent[nxtword].clear(); 
                            parent[nxtword].push_back(word); 
                        }

                        else if(dist[nxtword]== dist[word]+1){ 
                            parent[nxtword].push_back(word); 
                        }

                    }
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        path.push_back(endWord);
        backtrack(parent,endWord,res,path,beginWord);

        return res;

    }

    void backtrack(unordered_map<string,vector<string>>& parent,string node, vector<vector<string>>& res,vector<string>& path,string beginWord){

        if(node==beginWord){ 
            vector<string> a = path;
            reverse(a.begin(),a.end()); 
            res.push_back(a);

            return;
        }

        for(string& p : parent[node]){
            path.push_back(p);
            backtrack(parent,p,res,path,beginWord);
            path.pop_back();
        }
    }
};