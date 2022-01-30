#include "header.hpp"
class TrieNode
{
public:
    TrieNode *links[26];

    bool flag = false;

    bool hasKey(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }

    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }

    void flagSwitch()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag == true;
    }
};

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (const auto &ch : word)
        {
            if (!node->hasKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            //go to the next node along the ch
            node = node->get(ch);
        }
        //get to the end of the word
        node->flagSwitch();
    }

    bool search(string word)
    {
    }

    bool helper(string word, TrieNode *node)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == '.')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (node->hasKey(ch) && helper(word.substr(i + 1), node->get(ch)))
                        return true;
                }
                return false;
            }
            else
            {
                if (!node->hasKey(word[i]))
                {
                    return false;
                }
                node = node->get(word[i]);
            }
        }
        if (node->isEnd())
        {
            return true;
        }
        return false;
    }
};