class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int x=0;
        while(x<arr.size()-1){
            if(arr[x]>arr[x+1])break;
            x++;
        }
        if(x==arr.size()-1)return 0;
        int y=arr.size()-1;
        while(y>0){
            if(arr[y-1]>arr[y])break;
            y--;
        }
        int n=arr.size();
        int res=min(n-x-1,y);
        int i=0,j=y;
        while(i<=x && j<arr.size()){
            if(arr[i]<=arr[j]){
                res=min(res,j-i-1);
                i++;
            }
            else j++;
        }
        return res;
    }
};