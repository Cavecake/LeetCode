class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(maxJump < i) return false;
            maxJump = (maxJump < i + nums[i]) ? i + nums[i] : maxJump;
        }
        return true;
    }
};