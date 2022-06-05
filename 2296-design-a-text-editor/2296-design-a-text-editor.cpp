class TextEditor {
public:
    deque<char> s1;
    deque<char> s2;
    
    TextEditor() 
    {
        s1.clear();
        s2.clear();
    }
    
    void addText(string text) 
    {
        for(int i = 0; i < text.size(); i++) {
            s1.push_back(text[i]);
        }
    }
    
    int deleteText(int k) 
    {
        int cnt = 0;
        while(s1.size() > 0 && k > 0) {
            s1.pop_back();
            k--;
            cnt++;
        }
        
        return cnt;
    }
    
    string cursorLeft(int k) 
    {
        while(s1.size() > 0 && k > 0) 
        {
            s2.push_front(s1.back());
            s1.pop_back();
            k--;
        }
        
        string st = "";
        for(int i = 0; i < 10 && s1.size() > 0; i++) 
        {
            st += s1.back();
            s1.pop_back();
        }
        
        reverse(st.begin(), st.end());
        for(int i = 0; i < st.size(); i++) 
        {
            s1.push_back(st[i]);
        }
        
        return st;
    }
    
    string cursorRight(int k) 
    {
        while(s2.size() > 0 && k > 0) 
        {
            s1.push_back(s2.front());
            s2.pop_front();
            k--;
        }
        
        string st = "";
        for(int i = 0; i < 10 && s1.size() > 0; i++) 
        {
            st += s1.back();
            s1.pop_back();
        }
        
        reverse(st.begin(), st.end());
        for(int i = 0; i < st.size(); i++) 
        {
            s1.push_back(st[i]);
        }
        
        return st;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */