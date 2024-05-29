class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        
        if(target > nums[right]) return nums.size();
        if(target <= nums[0]) return 0;
        
        while(left + 1 < right){
            middle = left + (right - left)/2;

            //middle = (middle == right) ? middle - 1 : middle;
            middle = (middle == left) ? middle + 1 : middle;

            
            //cout << middle << " " << nums[middle] << " " << target << " " <<  left << " " << right << endl;
            //cout << nums[middle] << " " << target << endl;
            
            if(nums[middle] == target) return middle;
            if(nums[middle] > target) right = middle;
            else left = middle;
        }
        //cout << middle << " " << nums[middle] << " " << target << endl;
        return left + 1;
    }
};