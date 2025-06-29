/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    // Initialize to -1
    res[0] = -1;
    res[1] = -1;

    // Find first occurrence
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        if (nums[mid] == target) {
            res[0] = mid;
        }
    }

    // Find last occurrence
    left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        if (nums[mid] == target) {
            res[1] = mid;
        }
    }

    return res;
}
