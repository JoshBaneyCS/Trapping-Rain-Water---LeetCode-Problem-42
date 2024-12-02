#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        // Arrays to store the maximum heights to the left and right of each bar
        std::vector<int> leftMax(n), rightMax(n);
        
        // Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }
        
        // Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = std::max(rightMax[i + 1], height[i]);
        }
        
        // Calculate the total trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return water;
    }
};
