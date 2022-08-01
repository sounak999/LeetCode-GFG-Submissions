class TrieNode{
  public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    
    TrieNode(char c)
    {
        this->data = c;
        this->isTerminal = false;
        for(int i =0; i<26; i++)
            children[i] = nullptr;
    }
};

class Trie {
        TrieNode* root = new TrieNode('\0');
    
    public:
        void instUtil(TrieNode* root, string s)
        {
            if(s.length() == 0)
            {
                root->isTerminal = true;
                return ;
            }
            
            char c = s[0];
            int idx = c - 'a';
            TrieNode* child;
            
            
            if(root->children[idx] != nullptr)
                child = root->children[idx];
            else 
            {
                child = new TrieNode(c);
                root->children[idx] = child;
            }
            
            instUtil(child, s.substr(1));
        }
    
        void insert(string s)
        {
            instUtil(root, s);
        }
        
    
        int getChildCnt(TrieNode* temp)
        {
            int cnt = 0;
            for(int i=0; i<26; i++)
                if(temp->children[i])
                    cnt++;
            
            return cnt;
        }
    
        void lcp(string str, string& ans)
        {
            TrieNode* temp = root;
            for(int i=0; i<str.length(); i++)
            {
                char ch = str[i];
                if(getChildCnt(temp) == 1 && temp->isTerminal == false)
                {
                    ans.push_back(ch);
                    int idx = ch - 'a';
                    temp = temp->children[idx];
                }
                else 
                    break;
            }
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        for(string s: strs)
            trie->insert(s);
        
        string res = "";
        trie->lcp(strs[0], res);
        return res;
    }
};