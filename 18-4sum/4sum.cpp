class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        sort(nums.begin(),nums.end(), less<int>());
        for(int i = 0; i < nums.size();++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size(); ++j){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                for(int k = j + 1; k < nums.size(); ++k){
                    if(k > j + 1 && nums[k] == nums[k - 1]) continue;
                    // O (n^3)
                    long summe = nums[i];
                    summe += nums[j] + nums[k];
                    //cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << summe << endl;

                    long diff = target - summe;
                    if(diff > INT_MAX || diff < INT_MIN) continue;
                    //cout << diff << endl;
                    auto it = find(nums.begin() + k + 1, nums.end(), diff);
                    if(it != nums.end()){
                        int index = it - nums.begin();
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[index]};

                        //cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << nums[index] << endl;

                        if(find(quadruplets.begin(), quadruplets.end(),quadruplet) != quadruplets.end()) continue;
                        quadruplets.push_back(quadruplet);
                    }
                    
                }
            }
        }
        return quadruplets;
    }
};