class Solution {
public:
    void expand(string &s,int l, int r, int &max_len, int &st){
        int n = s.length();
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }else break;
            }
            int len = r-l-1;
            if(len>max_len){
                max_len = len;
                st = l+1;
                
            }
        }
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        int max_len = 1;
        int n = s.length();
        int st=0;
        
        for(int i=0;i<n;i++){
            expand(s,i,i,max_len,st);
            expand(s,i,i+1,max_len,st);
            
        }
        
        return s.substr(st, max_len);
    }
};