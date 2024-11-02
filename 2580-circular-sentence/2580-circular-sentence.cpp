class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i=2;i<sentence.size();i++){
            if(sentence[i-1]==' ' && sentence[i-2]!=sentence[i])return 0;
        }
        return sentence[0]==sentence[sentence.size()-1];
    }
};