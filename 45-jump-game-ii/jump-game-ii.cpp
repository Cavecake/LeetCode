class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dist;
        dist.resize(nums.size());
        dist[0] = nums[0];
        for(int i=1; i < nums.size(); i++){
            dist[i] = max(dist[i - 1], i + nums[i]);
        }
        int index = 0;
        int ans = 0;
        while(index < dist.size() - 1){
            index = dist[index];
            ans++;
        }
        return ans;
    }
};