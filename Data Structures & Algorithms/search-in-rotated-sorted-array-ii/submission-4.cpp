class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
             if (nums[mid] == target) return true;
            if(nums[l]==nums[mid]&& nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }

            // Check if the left half is sorted
            if (nums[l] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Search left
                } else {
                    l = mid + 1; // Search right
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[mid] <= target && target < nums[r]) {
                    l = mid + 1; // Search right
                } else {
                    r = mid - 1; // Search left
                }
            }
        }

        return false;
    }
};