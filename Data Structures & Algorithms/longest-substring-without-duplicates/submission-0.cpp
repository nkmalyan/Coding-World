class Solution {
public:
    int lengthOfLongestSubstring(string s){
        vector<int> lastSeen(128, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); ++right){
            char curr = s[right];

            if (lastSeen[curr] >= left){
                left = lastSeen[curr] + 1;
            }

            lastSeen[curr] = right;
            maxLength  =  max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};