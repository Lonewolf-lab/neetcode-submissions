class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int h = n-1;
        int l = 0;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(nums[mid] == target) return mid;

            else if (target < nums[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};