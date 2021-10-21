class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, len = 0;
        map<char, int> dict;
        for (int right=0; right<s.size(); right++) {
            if (dict.find(s[right]) != dict.end()) {
                left = max(left, dict[s[right]] + 1);
            }
            dict[s[right]] = right;
            len = max(len, right - left + 1);
        }
        return len;
    }
};
