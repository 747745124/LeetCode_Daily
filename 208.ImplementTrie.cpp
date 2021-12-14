#pragma once
#include "header.hpp"
class Trie
{
public:
    // initialize Trie with its root node set
    Trie() : root(new TrieNode()){};

    void insert(string &word)
    {
        TrieNode *p = root.get();
        //for char in word
        for (const auto &ch : word)
        { //if char not found in p, generate new node, go to the node
            if (!p->children.count(ch))
                p->children[ch] = new TrieNode();
            //if found in p, just go to the next node
            p = p->children[ch];
        }
        //at the last node, set is_word
        p->is_word = true;
        //store the word pointer for fast access
        p->word = &word;
    }

    bool search(string &word)
    {
        const TrieNode *res = find(word);
        if (!res)
            return false;
        if (!res->is_word)
            return false;
        return true;
    }

    bool startsWith(string &prefix)
    {
        const TrieNode *res = find(prefix);
        if (!res)
            return false;
        return true;
    }

    // private:
    struct TrieNode
    {

        TrieNode() : is_word(false), word(nullptr){};
        ~TrieNode()
        {
            for (auto &kv : children)
            {
                //if it has children, delete
                if (kv.second)
                    delete kv.second;
            }
        }
        bool is_word;
        const string *word;
        unordered_map<char, TrieNode *> children;
    };

    //given a word, check if it's found from the rootnode, if all found, go to the leaf node;
    const TrieNode *find(const string &prefix) const
    {
        const TrieNode *p = root.get();
        for (const char ch : prefix)
        {
            //check if key ch exist
            if (!p->children.count(ch))
                return nullptr;
            //if exist, go to the next child
            // we have to use at here, becuase it's a const member function, meaning it won't change the children hashmap
            // however, [] operator is non-const, if [k] not exist, it will automatically insert a new kv.
            // while at is const, throw exception if [k] not exist.
            p = p->children.at(ch);
        }
        return p;
    };

    unique_ptr<TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */