class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<int>arr[box.size()];
        vector<vector<char>>res(box[0].size(),vector<char>(box.size(),'.'));
        for(int i=0;i<box.size();i++){
            int c=0;
            for(int j=0;j<box[0].size();j++){
                if(box[i][j]=='#')c++;
                if(box[i][j]=='*'){
                    res[j][box.size()-i-1]='*';
                    arr[i].push_back(c);
                    c=0;
                }
            }
            arr[i].push_back(c);
            c=0;
        }
        // cout<<res.size()<<' '<<res[0].size();
        // vector<vector<int>>res(box[0].size(),vector<int>(box.size()),*);
        int x=box.size()-1;
        for(int i=0;i<res[0].size();i++){
            int val=arr[x].size()-1;
            int c=arr[x][val];
            for(int j=res.size()-1;j>=0;j--){
                if(res[j][i]=='*'){
                    val--;
                    c=arr[x][val];
                }
                else{
                    if(c>0){
                        res[j][i]='#';
                        c--;
                    }
                }

            }
            x--;
            // cout<<endl;
        }
        return res;
    }
};