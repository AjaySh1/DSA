class Solution {
public:
    int minMaxDifference(int num) {
             string s=to_string(num);
             int i=0;
             while(s[i]=='9'){i++;}
             char ss=s[i];
             while(i<s.size()){
                if(s[i]==ss)s[i]='9';
                i++;
             }
             

             string k=to_string(num);
             ss=k[0];
             i=0;
             while(i<k.size()){
                if(k[i]==ss)k[i]='0';
                i++;
             }

             return stoi(s)-stoi(k);
    }
};