class Solution {
public:
    bool isValid(std::string s) {
        // Max-heap storing pairs of <int, char> -> <index, bracket_character>
        // C++ priority_queue sorts pairs by the first element (index) by default
        std::priority_queue<std::pair<int, char>> heap;
        int index = 0;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                heap.push({index, c});
                index++;
            } else {
                if (heap.empty()) {
                    return false;
                }
                
                // Get the most recent opening bracket (highest index)
                char top_char = heap.top().second;
                heap.pop();
                
                // Validate match
                if ((c == ')' && top_char != '(') || 
                    (c == '}' && top_char != '{') || 
                    (c == ']' && top_char != '[')) {
                    return false;
                }
            }
        }
        
        return heap.empty();
    }
};
