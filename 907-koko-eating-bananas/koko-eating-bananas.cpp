#include <bits/stdc++.h>
class Solution {
public:
    int findMax(vector<int> &piles){
        int n = piles.size();
        int Maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            Maxi = max(Maxi, piles[i]);
        }
        return Maxi;
    }
    long long calcTotalHours(vector<int>& piles,int mid){
        long long totalH = 0;
        int n = piles.size();
        for (int i = 0; i<n; i++){
            totalH += (long long) ceil((double)piles[i]/(double)mid);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            long long totalH = calcTotalHours(piles, mid);
            if (totalH<=h){
                high = mid - 1;
                
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};