class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,1), r(n,1), ans(n);
        int lProd = 1, rProd = 1;

        for(int i = 1; i<n; i++){
            lProd *= nums[i-1];
            l[i] = lProd;
        }
        for(int i=n-2; i>=0; i--){
            rProd *= nums[i+1];
            r[i] = rProd;
        }
        for(int i=0; i<n; i++){
            ans[i] = l[i] * r[i];
        }
        return ans;
    }
};