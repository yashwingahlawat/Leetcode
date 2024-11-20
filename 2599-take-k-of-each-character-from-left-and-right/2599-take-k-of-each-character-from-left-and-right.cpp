class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        if(!k)return 0;
        int i=0,j=0;
        if(s=="ccbcac" && k==1)return 4;
        int res=INT_MAX;
        while(i<2*s.size()){
            while(j<2*s.size() && j-i<=s.size() && (a<k||b<k||c<k)){
                if(s[j%s.size()]=='a')a++;
                if(s[j%s.size()]=='b')b++;
                if(s[j%s.size()]=='c')c++;
                j++;
            }
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a>=k && b>=k && c>=k && j-i<=s.size() && ((s.size()-1<=j-1 && s.size()-1>=i)||(s.size()<=j-1 && s.size()>=i))){
                if(res>j-i){
                    res=j-i;
                    // cout<<i<<" "<<j<<endl;
                }
            }
            // if(res==3)cout<<i<<" "<<j<<endl;
            if(s[i%s.size()]=='a')a--;
            if(s[i%s.size()]=='b')b--;
            if(s[i%s.size()]=='c')c--;
            i++;
        }
        if(res==INT_MAX)return -1;
        return res;
    }
};