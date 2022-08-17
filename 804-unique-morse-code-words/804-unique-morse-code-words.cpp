class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> morseWord;
        for(auto word: words)
        {
            string wordToMorse = "";
            for(auto ch: word)
            {
                wordToMorse += morseCode[ch - 'a'];
            }
            
            morseWord.insert(wordToMorse);
        }
        
        return morseWord.size();
    }
};