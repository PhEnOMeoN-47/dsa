class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // better : hashmap
        /*
        map<int, int> mpp;
        int more = 0;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more)!=mpp.end()){
                return {i, mpp[more]};
            }
            mpp[a] = i;
        }
    return {1, mpp[more]};
    */

        // optimal : 2 pointers but here we need to sort using vector<pair<int,int>>
        // which will result TC = O(N logN)
        int sum = 0;
        int n = nums.size();
        int left = 0, right = n-1;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        while(left < right){
            sum = v[left].first + v[right].first;   //first has element in pair dataset
            if(sum == target){
                return {v[left].second, v[right].second};  //second has index in pair dataset
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
        
};