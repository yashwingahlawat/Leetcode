class Solution {
public:
    int findPeakElement(vector<int>& temp) {
        if(temp.size()==1)return 0;
        if(temp[0]>temp[1])return 0;
        if(temp[temp.size()-1]>temp[temp.size()-2])return temp.size()-1;
        int s=1,e=temp.size()-2;
        while(s<=e){
            int m=s+(e-s)/2;
            if(temp[m]>temp[m-1] && temp [m]>temp[m+1])return m;
            else if(temp[m]<temp[m-1]){
                e=m-1;
            }
            else s=m+1;
        }
        return -1;
    }
};