class Solution {
public:
    vector<string> ans;

    void solve(int index, string &digits,
               string &temp, vector<string> &mp) {

        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            temp.push_back(ch);

            solve(index + 1, digits, temp, mp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string temp = "";

        solve(0, digits, temp, mp);

        return ans;
    }
};