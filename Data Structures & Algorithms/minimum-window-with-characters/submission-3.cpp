class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int minlength = INT_MAX;
        int sindex = -1;

        unordered_map<char, int> tocount;

        for (char c : t) {
            tocount[c]++;
        }

        int l = 0;
        int r = 0;
        int cnt = 0;

        while (r < n) {

            // Add s[r] to the window
            if (tocount[s[r]] > 0) {
                cnt++;
            }

            tocount[s[r]]--;

            // Window contains all characters of t
            while (cnt == t.length()) {

                // Update minimum window
                if (r - l + 1 < minlength) {
                    minlength = r - l + 1;
                    sindex = l;
                }

                // Remove s[l] from window
                tocount[s[l]]++;

                if (tocount[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlength);
    }
};