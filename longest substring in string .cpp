//
// Created by PravinMore on 11/01/2026.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   // last seen index of characters
        int left = 0, ans = 0;

        cout << "String: " << s << "\n\n";

        for (int right = 0; right < s.size(); right++) {

            cout << "Processing character '" << s[right]
                 << "' at index " << right << endl;

            // If character seen and inside current window
            if (last[s[right]] >= left) {
                cout << "  Repeated! Moving left from "
                     << left << " to " << last[s[right]] + 1 << endl;
                left = last[s[right]] + 1;
            }

            last[s[right]] = right;

            int currentLen = right - left + 1;
            ans = max(ans, currentLen);

            cout << "  Window: [" << left << ", " << right << "] -> \""
                 << s.substr(left, currentLen) << "\"" << endl;
            cout << "  Current Length: " << currentLen << endl;
            cout << "  Max Length so far: " << ans << "\n\n";
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "dddcccbbbaa";
    //cout << "Enter string: ";
    //cin >> s;

    int result = sol.lengthOfLongestSubstring(s);

    cout << "\nFinal Answer (Longest Substring Length): "
         << result << endl;

    return 0;
}
