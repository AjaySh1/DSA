class Solution {
public:
    string answerString(string word, int num) {
          if (num == 1) return word;
        int maxLen = word.size() - num + 1;  
        string result = "";

        for(int i=0; i<word.size(); i++)
          { 
            result = max(result, word.substr(i, maxLen));
          }
        return result;
    }
};