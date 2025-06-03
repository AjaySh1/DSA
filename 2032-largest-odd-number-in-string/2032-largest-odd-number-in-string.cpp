class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int j=n-1;
        while(j>=0&&(num[j]-'0')%2==0)
        j--;
    
        return num.substr(0,j+1);
        
    }
};