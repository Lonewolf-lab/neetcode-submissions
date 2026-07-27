class Solution {
public:
    typedef pair<int, int> P;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<P> st;
        vector<int> days(n,0);

        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                int prevIdx = st.top().second;
                days[prevIdx] = i - prevIdx;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return days;
    }
};