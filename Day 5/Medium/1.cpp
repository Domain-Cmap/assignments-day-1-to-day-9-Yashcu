class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        for(int i=0; i<n; i++)
        {
            bool result= binarySearch(matrix[i], target);
            if(result) return true;
        }
        return false;
    }
    bool binarySearch(vector<int> nums, int target)
    {
       
        int n=nums.size();
        int low=0, high=n-1;

        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target) return true;
            else if(nums[mid] > target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};