int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Left part is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // search left half
            } else {
                left = mid + 1; // search right half
            }
        }
        // Right part is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // search right half
            } else {
                right = mid - 1; // search left half
            }
        }
    }

    return -1; 
}
