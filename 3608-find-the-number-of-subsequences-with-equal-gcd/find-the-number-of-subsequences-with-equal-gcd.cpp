class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const int MAX = 200;

        vector<vector<long long>> dp(MAX + 1,
                                     vector<long long>(MAX + 1, 0));

        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> ndp = dp;

            for (int g1 = 0; g1 <= MAX; g1++) {
                for (int g2 = 0; g2 <= MAX; g2++) {
                    if (dp[g1][g2] == 0)
                        continue;

                    // Put x in seq1
                    int ng1 = gcd(g1, x);

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + dp[g1][g2]) % MOD;

                    // Put x in seq2
                    int ng2 = gcd(g2, x);

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};