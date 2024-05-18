class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Iterate throug every element
        // check if difference is in list
        // return indecies
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            auto it = find(nums.begin(), nums.end(), diff);
            if(it != nums.end()){
                int index = it - nums.begin();
                if(index == i) continue;

                vector<int> ret{i, index};
                return ret;
            }
        }
        vector<int> ret{};
        return ret;
    }
};