class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end(), less<int>());
        for(int i = 0; i<nums.size();++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int subSum = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while(j<k){
                if(nums[j] + nums[k] == subSum){
                    triplets.push_back(
                        {nums[i], nums[j], nums[k]});
                }
                if(nums[j] + nums[k] > subSum){
                    do{
                    --k;
                    }
                    while(k>0 && nums[k] == nums[k+1]);
                    continue;
                }
                do{
                    ++j;
                }
                while(j < nums.size() && nums[j] == nums[j-1]);
                

            }
        }
        return triplets;
    }
};