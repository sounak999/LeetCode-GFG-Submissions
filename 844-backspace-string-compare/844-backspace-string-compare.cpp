class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string aux = "";
        for(char c: s)
        {
            if(c == '#')
            {
                if(aux.size() > 0)
                    aux.pop_back();
            }    
            else
                aux += c;
        }
        
        string aux2 = "";
        for(char c: t)
        {
            if(c == '#')
            {
                if(aux2.size() > 0)
                    aux2.pop_back();
            }
            else
                aux2 += c;
        }
        
        // cout<<aux<<" "<<aux2<<endl;
        return (aux == aux2);
    }
};