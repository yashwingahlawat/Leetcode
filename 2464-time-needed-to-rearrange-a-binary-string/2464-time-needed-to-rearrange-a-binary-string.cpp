class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res=0;
        for(int i=1;i<s.size();i++){
            bool x=0;
            for(int j=1;j<s.size();j++){
                if(s[j]=='1' && s[j-1]=='0'){
                    x=1;
                    swap(s[j],s[j-1]);
                    j++;
                }
            }
            if(!x)return res;
            res+=x;
        }
        return res;
    }
};