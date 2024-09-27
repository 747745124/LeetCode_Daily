#include "header.hpp"

class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    int count = 0;
};

class Trie{
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(const string& str){
        auto node = root;
        for(const auto&ch:str){
            if(!node->children.count(ch))
                node->children[ch] = new TrieNode();        
            node = node->children[ch];
            node->count++;
        }
    }

    int findScore(const string& str){
        int sum = 0;
        auto node = root;
        for(const auto&ch:str){
            node = node->children[ch];
            sum+=node->count;
        }

        return sum;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(const auto& word:words)
            trie.insert(word);
        
        vector<int> scores;
        for(const auto&word:words)
            scores.emplace_back(trie.findScore(word));
        
        return scores;
    }
};