class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target, int n2, int n3){
        while(n2 < n3){
            if(nums[n2] + nums[n3] > target){
                n3--;
            }
            else if(nums[n2] + nums[n3] < target){
                n2++;
            }
            else{
                while(n2<n3 && nums[n2] == nums[n2 + 1]) n2++;

                while(n2<n3 && nums[n3] == nums[n3 - 1]) n3--;

                result.push_back({-target, nums[n2], nums[n3]});

                n2++;n3--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return {};
        }
        sort(nums.begin(), nums.end());
        result.clear();
        for(int i = 0;i<n - 2;i++){
            if(i> 0 && nums[i] == nums[i-1]) continue;

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i+1, n-1);
        }
        return result;
    }
};