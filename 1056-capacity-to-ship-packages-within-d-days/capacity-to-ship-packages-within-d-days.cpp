class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int d = 1, load = 0;
        for (int i = 0; i<weights.size(); i++){
            if(load + weights[i] > cap){
                d += 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // max element
        int high = accumulate(weights.begin(), weights.end(), 0); //sum of array
        while(low<=high){
            int mid = low + (high-low)/2;
            if (findDays(weights, mid) <= days){
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};