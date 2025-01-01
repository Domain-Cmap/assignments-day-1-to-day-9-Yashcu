class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i =0,j=i+1;j<nums.size();i++,j++)
        {
            if(nums[j]<nums[i])return nums[j];
        }
        return nums[0];
    }
};