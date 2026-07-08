#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long MOD = 1e9 + 7;
        int n = s.length();
        
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<int> prefix_nz_count(n + 1, 0);
        vector<long long> prefix_digit_sum(n + 1, 0);
        vector<long long> prefix_val(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            prefix_nz_count[i + 1] = prefix_nz_count[i];
            prefix_digit_sum[i + 1] = prefix_digit_sum[i] + d;
            prefix_val[i + 1] = prefix_val[i];
            
            if (d != 0) {
                prefix_nz_count[i + 1]++;
                prefix_val[i + 1] = (prefix_val[i] * 10 + d) % MOD;
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            long long digit_sum = prefix_digit_sum[r + 1] - prefix_digit_sum[l];
            if (digit_sum == 0) {
                ans.push_back(0);
                continue;
            }
            
            int nz_in_window = prefix_nz_count[r + 1] - prefix_nz_count[l];
            
            long long val_r = prefix_val[r + 1];
            long long val_l = prefix_val[l];
            
            long long x = (val_r - (val_l * pow10[nz_in_window]) % MOD + MOD) % MOD;
            
            ans.push_back((x * digit_sum) % MOD);
        }
        
        return ans;
    }
};