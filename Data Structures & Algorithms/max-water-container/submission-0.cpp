class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_ptr = 0;
        int right_ptr = height.size() - 1;
        int max_area = 0;
        
        while (left_ptr < right_ptr) {
            int current_width = right_ptr - left_ptr;
            int current_height = min(height[left_ptr], height[right_ptr]);
            int current_area = current_width * current_height;

            max_area = max(max_area, current_area);
            
            if (height[left_ptr] < height[right_ptr]) {
                left_ptr++;
            } else {
                right_ptr--;
            }
        }
        
        return max_area;
    }
};