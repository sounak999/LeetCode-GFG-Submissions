class TrieNode{
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];
    
    TrieNode(char d)
    {
        this->data = d;
        isTerminal = false;
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string str)
    {
        if(str.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }
        
        TrieNode* child = nullptr;
        int index = str[0] - 'a';
        
        if(root->children[index])
        {
            child = root->children[index];
        }
        else 
        {
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }
        
        insertUtil(child, str.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }
    
    
    bool searchUtil(TrieNode* root, string word, int i)
    {
        if(i == word.length())
        {
            return root->isTerminal;
        }
        
        int index = word[i] - 'a';
        TrieNode* child = nullptr;
        
        if(root->children[index])
            child = root->children[index];
        else
            return false;
        
        bool rem = searchUtil(child, word, i+1); 
        return rem;
    }
    
    bool search(string word) {
        return searchUtil(root, word, 0);
    }
    
    bool prefixOrNot(TrieNode* root, string pre)
    {
        if(pre.length() == 0)
            return true;
        
        char ch = pre[0];
        int idx = ch - 'a';
        TrieNode* child = nullptr;
        
        if(root->children[idx]) 
        {
            child = root->children[idx];
            bool rem = prefixOrNot(child, pre.substr(1));
            return rem;
        }
         
        return false;
    }
    
    bool startsWith(string prefix) {
        return prefixOrNot(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */