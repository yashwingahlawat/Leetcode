class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res;
        if(k==0){
            vector<int>t(code.size(),0);
            return t;
        }
        if(k<0){
            int val=0;
            for(int i=-1;i>=k;i--){
                int t=i+code.size();
                val+=code[t%code.size()];
            }
            res.push_back(val);
            for(int i=1;i<code.size();i++){
                val+=code[(i-1)%code.size()];
                int t=code.size()+k+i-1;
                val-=code[t%code.size()];
                // cout<<code[(i-1)%code.size()]<<" "<<code[t%code.size()]<<endl;
                res.push_back(val);
            }
        }
        else{
            int val=0;
            for(int i=1;i<=k;i++){
                val+=code[i%code.size()];
            }
            res.push_back(val);
            for(int i=1;i<code.size();i++){
                val-=code[i];
                int t=i+code.size()+k;
                val+=code[t%code.size()];
                res.push_back(val);
            }
        }
        return res;
        
    }
};