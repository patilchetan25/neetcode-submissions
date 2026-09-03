class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (char c : s1) {
            count1[c - 'a']++;
        }

        int k = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            // Add new character
            count2[s2[i] - 'a']++;

            // Remove character leaving the window
            if (i >= k) {
                count2[s2[i - k] - 'a']--;
            }

            // Check current window
            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};
