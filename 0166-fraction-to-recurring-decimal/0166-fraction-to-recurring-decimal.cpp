class Solution {
public:
    string fractionToDecimal(int nums, int dens) {
         if(!nums) return "0";
        string ans = "";
        if (nums > 0 ^ dens> 0) ans += '-';
        long num = labs(nums), den = labs(dens);
        long q = num / den;
        long r = num % den;
        ans += to_string(q);
        
        if(r == 0) return ans;
        
        ans += '.';
        unordered_map<long, int> mp;
        while(r != 0){
            if(mp.find(r) != mp.end()){
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else{
                mp[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
        return ans;
    }
};