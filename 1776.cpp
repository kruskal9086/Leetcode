#define ll long long

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        vector<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && cars[st.back()][1] >= cars[i][1] || st.size() > 1 && (ll)(cars[i][0] - cars[st.back()][0]) * (cars[st[st.size() - 2]][1] - cars[st.back()][1]) > (ll)(cars[st.back()][0] - cars[st[st.size() - 2]][0]) * (cars[st.back()][1] - cars[i][1])) {
                st.pop_back();
            }
            if (st.size()) {
                ans[i] = (double)(cars[i][0] - cars[st.back()][0]) / (cars[st.back()][1] - cars[i][1]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
