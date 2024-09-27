#include "header.hpp"

class TrieNode{
public:
    vector<TrieNode*> children;
    TrieNode(){
        for(int i=0; i<10;i++)
            children.push_back(nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){root = new TrieNode();}

    void insert(int num){
        auto node = root;
        string numStr = to_string(num);
        for (const auto& digit : numStr) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int findLongestPrefixNum(int num)
    {
        TrieNode* node = root;
        string numStr = to_string(num);
        int len = 0;

        for(const auto& ch:numStr){
            int idx = ch - '0';
            if(node->children[idx]!=nullptr){
                len++;
                node = node->children[idx];
            }
            else{
                break;
            }
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        // Step 1: Insert all numbers from arr1 into the Trie
        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        // Step 2: Find the longest prefix match for each number in arr2
        for (int num : arr2) {
            int len = trie.findLongestPrefixNum(num);
            longestPrefix = max(longestPrefix, len);
        }

        return longestPrefix;
    }
};