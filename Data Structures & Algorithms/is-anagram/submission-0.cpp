class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

      vector<int> count(26, 0);
        
        for (int i = 0; i < (int)s.length(); i++) {
            count[s[i] - 'a']++; 
            count[t[i] - 'a']--; 
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        } 
        return true;
    }
};
