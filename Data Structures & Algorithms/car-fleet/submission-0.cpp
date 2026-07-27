class Solution {
public:
    typedef pair<int,int> P;
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<P> cars;
        for(int i = 0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack<double> st;
        for(int i = n-1; i>=0; i--){
            double time_to_target = (double)(target - cars[i].first)/cars[i].second;
            if(st.empty() || time_to_target > st.top()){
                st.push(time_to_target);
            }
        }
        return st.size();
    }
};