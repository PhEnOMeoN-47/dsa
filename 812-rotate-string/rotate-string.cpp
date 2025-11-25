class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1, q2;
        for(int i=0; i<s.length();i++){
            q1.push(s[i]);
        }
        for (int i=0; i<goal.length();i++){
            q2.push(goal[i]);
        }

        int k = goal.length();
        while(k--){
            if(q1==q2){
                return true;
            }
            char c = q2.front();
            q2.pop();
            q2.push(c);

            
        }
    return false;
    }
};