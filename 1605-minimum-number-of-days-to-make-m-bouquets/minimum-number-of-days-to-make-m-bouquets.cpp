class Solution {
public:
    int possible(vector<int> &bloomDay, int day, int m, int k){
        int count = 0;
        int numBouquet = 0;
        for (int i=0; i<bloomDay.size(); i++){
            if (bloomDay[i]<=day){
                count += 1;
            }
            else {
                numBouquet += (count/k);
                count = 0;
            }
        }
        numBouquet += (count/k);
        return numBouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int val = m * 1LL * k * 1LL ; // to convert into long long
        if(val>bloomDay.size()) return -1;
        int mini = INT_MAX , maxi = INT_MIN;
        for (int i = 0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (possible(bloomDay, mid, m, k)){
                high = mid-1;
            }
            else {
                low = mid+1 ;
            }
        }
        return low;
        
    }
};