class Solution {
public:
    string minWindow(string s, string t){
        if(s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> tCount(128, 0);
        int required = 0;
        for(char c : t){
            if(tCount[c] == 0){
                required++;
            }
            tCount[c]++;
        }

        vector<int> windowCount(128, 0);
        int formed = 0;
        int left = 0;
        
        int minLen = INT_MAX;
        int startIndex = 0;

        for(int right = 0; right < (int)s.length(); ++right){
            char c = s[right];
            windowCount[c]++;

            if(tCount[c] > 0 && windowCount[c] == tCount[c]){
                formed++;
            }
            while(left <= right && formed == required){
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                char removeChar = s[left];
                windowCount[removeChar]--;
                if(tCount[removeChar] > 0 && windowCount[removeChar] < tCount[removeChar]){
                    formed--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
