class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n-1;
        while (low<=high){
            int mid = low+(high-low)/2;
            if (nums[mid]==x) return true;
            if (nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++, high--;
                continue;
            }
            if (nums[low]<=nums[mid]){  //left sorted
                if (nums[low]<=x && x<= nums[mid]){
                    high = mid-1;
                }
                else {
                    low = mid+1; 
                }
            }
            else {
                if (nums[mid]<=x && x<= nums[high]){
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return false;
    }
};