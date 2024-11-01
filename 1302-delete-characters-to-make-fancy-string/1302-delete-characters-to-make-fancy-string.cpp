class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int c=1;
        char prev='.';
        for(auto i:s){
            if(i!=prev){
                c=1;
                res+=i;
                prev=i;
            }
            else{
                if(c<2){
                    res+=i;
                    c++;
                }

            }
        }
        return res;
    }
};