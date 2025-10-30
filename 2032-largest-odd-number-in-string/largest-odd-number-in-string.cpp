class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        
        
        if ((num.back() - '0')%2!=0){
            ans = num;
        }
        for (int i = num.length()-1; i>=0; i--){
            int odd = num[i];
            if(odd%2!= 0){
                ans = num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};