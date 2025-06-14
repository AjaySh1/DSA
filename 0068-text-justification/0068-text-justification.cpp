class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int w) {
        int n=words.size();
        vector<string>v;
         int i=0,j=0;
         while(i<n){
            int count=0;
            int num=0;
            int prev=i;
            int extra=0;
            while(prev<n&&(count+words[prev].length()<=w))
            {
             count+=words[prev].length()+1;
             extra+=words[prev].length();
             num++;
             prev++;
            }
            if(prev==n)
            {
                string cur="";
                for(int j=i;j<prev;j++)
                {
                    if(j==i)
                    {
                        cur=words[j];

                    }else
                    {
                        cur=cur+" "+words[j];
                    }
                }
                
                v.push_back(cur+string(w-cur.size(),' '));
                break;
            }
            if(num==1)
            {
             string temp(w-words[i].size(),' ');
             v.push_back(words[i]+temp);
             i=prev;
             continue;
            }
            int space=(w-extra)/(num-1);
            int norm=(w-extra)%(num-1);
            string temp(space,' ');
            string cur="";
                for(int j=i;j<prev;j++)
                {
                    if(j==i)
                    {
                        cur=words[j];

                    }else
                    {
                        string c="";
                        if(norm>0)
                        {
                            c=" ";
                            norm--;
                        }
                        cur=cur+temp+c+words[j];
                    }
                }
                v.push_back(cur);
          i=prev;
         }

        return v;
    }
};