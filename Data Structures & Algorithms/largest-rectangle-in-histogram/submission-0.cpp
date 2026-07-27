class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int  nextSmall, prevSmall, element;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                nextSmall = i;
                if(st.empty()) prevSmall = -1;
                else prevSmall = st.top();
                maxArea = max(maxArea, heights[element] * (nextSmall - prevSmall - 1)); 
            }
            st.push(i);
        }
            while(!st.empty()){
                nextSmall = n;
                element = st.top();
                st.pop();
                if(st.empty()) prevSmall = -1;
                else prevSmall = st.top();
                maxArea = max(maxArea, heights[element] * (nextSmall - prevSmall - 1));
            }
        return maxArea;
    }
};