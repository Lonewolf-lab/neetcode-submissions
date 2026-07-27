class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int maxCap = 0;
        
        while(i < j){
            int width = j-i;
            int area = width * min(height[i], height[j]);
            
            maxCap = max(maxCap, area);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxCap;
    }
};