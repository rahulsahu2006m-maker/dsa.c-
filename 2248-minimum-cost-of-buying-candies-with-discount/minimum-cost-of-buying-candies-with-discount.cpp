class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i += 3) {
            ans += cost[i];

            if (i + 1 < cost.size())
                ans += cost[i + 1];
        }

        return ans;
    }
};