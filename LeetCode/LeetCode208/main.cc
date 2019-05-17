#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() 
        :root(new TrieNode())
    {}
    ~Trie()
    {
        if(root)
            delete root;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto c : word){
            if(!node->child[c-'a']){
                node->child[c-'a'] = new TrieNode();
            }
            node = node->child[c-'a'];
        }
        node->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word)const {
        const TrieNode* node = find(word);
        return node && node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
private:
    struct TrieNode{
      TrieNode()
          :child(26,nullptr)
          ,is_word(false)
        {}
        ~TrieNode()
        {
            for(auto e:child){
                if(e){
                    delete e;
                }
            }
        }
        vector<TrieNode*> child;
        bool is_word;
    };
    const TrieNode* find(const string& prefix)const{
        const TrieNode* node = root;
        for(auto c : prefix){
            node = node->child[c-'a'];
            if(!node)
                return nullptr;
        }
        return node;
    }
    TrieNode* root;
};
int main()
{
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl; // returns true

    return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
