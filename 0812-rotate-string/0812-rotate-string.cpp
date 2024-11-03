class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        while(n--){
            if(s==goal)return 1;
            char x=s[s.size()-1];
            s.pop_back();
            string temp="";
            temp+=x;
            temp+=s;
            s=temp;
        }
        return 0;
    }
};