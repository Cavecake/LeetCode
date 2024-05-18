class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        for(int i = 0; i < nums.size();++i){
            for(int j = i + 1; j < nums.size(); ++j){
                for(int k = j + 1; k < nums.size(); ++k){
                    // O (n^3)
                    long long summe = nums[i];
                    summe += nums[j] + nums[k];
                    if(summe > INT_MAX){
                        continue;
                    }
                    long diff = target - summe;
                    auto it = find(nums.begin() + k + 1, nums.end(), diff);
                    if(it != nums.end()){
                        int index = it - nums.begin();
                        vector<int> quadruplet = 
                        {nums[i], nums[j], nums[k], nums[index]};
                        
                        sort(quadruplet.begin(), quadruplet.end(),greater<int>());

                        if(find(quadruplets.begin(), quadruplets.end(),quadruplet) != quadruplets.end()) continue;
                        quadruplets.push_back(quadruplet);
                    }
                    
                }
            }
        }
        return quadruplets;
    }
};