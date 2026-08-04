class Solution {
public:
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        int xorVal = n; // Start with n since loop indices go from 0 to n-1
        
        for (int i = 0; i < n; ++i){
            xorVal ^= i ^ nums[i];
        }
        
        return xorVal;
    }
};

