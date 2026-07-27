class Solution {
public:
    void findCombination(int i, int target, vector<int>& arr, vector<vector<int>>& result, vector<int>& ds){
        if(i == arr.size()){
            if(target == 0) result.push_back(ds);
            return;
        }

        if(arr[i] <= target){
            ds.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, result, ds);
            ds.pop_back();
        }

        findCombination(i+1, target, arr, result, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        findCombination(0, target, candidates, result, ds);
        return result;
    }
};