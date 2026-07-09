class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
    long ans=0;
        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 &&
                 digit > (sign == 1 ? 7 : 8))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans =( ans * 10) + digit;
            i++;
        }

        return sign * ans;
    }
};