class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()==1)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[arr.size()-1]>arr[arr.size()-2])return arr.size()-1;
        int s=1,e=arr.size()-2;
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]>arr[m-1] && arr [m]>arr[m+1])return m;
            else if(arr[m]<arr[m-1])e=m-1;
            else s=m+1;
        }
        return -1;
    }
};
