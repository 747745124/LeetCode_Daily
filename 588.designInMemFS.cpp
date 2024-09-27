#include "header.hpp"

class Node{
    public:
        unordered_map<string, Node*> children;
        bool isFile = false;
        string content = "";
};

class FileSystem {

private:
    Node* root = nullptr;
    vector<string> split(string path) {
        vector<string> res;
        int i = 1;
        while (i < path.size()) {
            int j = i;
            while (j < path.size() && path[j] != '/') {
                j++;
            }
            res.push_back(path.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }
    
public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        auto strs = split(path);
        auto node = root;

        for(const auto& str : strs) {
            node = node->children[str];
        }

        if(node->isFile)
            return {strs.back()};
        
        vector<string> res;
        for(const auto& kv:node->children)
            res.push_back(kv.first);
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {

        auto strs = split(path);
        auto node = root;

        for(int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            if(node->children.count(str))
                node = node->children[str];
            else
            {
                node->children[str] = new Node();
                node = node->children[str];
            }
        }

        return;
    }
    
    void addContentToFile(string filePath, string content) {
        auto strs = split(filePath);
        auto node = root;

        for(int i = 0; i < strs.size(); i++) {

            if(i == strs.size()-1)
            {   
                if(node->children.count(strs.back()))
                {
                    node->children[strs.back()]->content += content;
                }
                else{
                    auto leaf = new Node();
                    leaf->content = content;
                    leaf->isFile = true;
                    node->children[strs.back()] = leaf;
                }

                return;
            }

            auto str = strs[i];
            if(node->children.count(str))
                node = node->children[str];
            else
                {
                    auto next = new Node();
                    node->children[str] = next;
                    node = next;
                }
        }

        return;
    }
    
    string readContentFromFile(string filePath) {
        auto strs = split(filePath);
        auto node = root;

        for(int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            if(node->children.count(str))
                node = node->children[str];
        }

        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

int main(){
    FileSystem* obj = new FileSystem();
    vector<string> param_1 = obj->ls("/");
    obj->mkdir("/a/b/c");
    obj->addContentToFile("/a/b/c/d", "hello");
    obj->ls("/");
    return 0;
}