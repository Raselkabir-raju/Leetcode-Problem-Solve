int* maxSubsequence(int* nums, int numsSize, int k) {
    int *stack = (int*)malloc(sizeof(int)*k);
    int top = -1;
    int toRemove = numsSize - k;
    for (int i = 0; i < numsSize; i++) {
        while (top >= 0 && stack[top] < nums[i] && toRemove > 0) {
            top--;
            toRemove--;
        }
        if (top < k - 1) {
            stack[++top] = nums[i];
        } else {
            toRemove--;
        }
    }
    return stack;
}

int compare(int* nums1, int i, int nums1Size, int* nums2, int j, int nums2Size) {
    while (i < nums1Size && j < nums2Size && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    if (j == nums2Size) return 1;
    if (i == nums1Size) return 0;
    return nums1[i] > nums2[j];
}

int* merge(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int *merged = (int*)malloc(sizeof(int)*k);
    int i = 0, j = 0, r = 0;
    while (r < k) {
        if (compare(nums1, i, nums1Size, nums2, j, nums2Size))
            merged[r++] = nums1[i++];
        else
            merged[r++] = nums2[j++];
    }
    return merged;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize){
    int *result = (int*)calloc(k, sizeof(int));
    *returnSize = k;

    for (int i = (k > nums2Size) ? k - nums2Size : 0; i <= (k < nums1Size ? k : nums1Size); i++) {
        int len1 = i;
        int len2 = k - i;
        int* subseq1 = maxSubsequence(nums1, nums1Size, len1);
        int* subseq2 = maxSubsequence(nums2, nums2Size, len2);
        int* candidate = merge(subseq1, len1, subseq2, len2, k);
        
        int better = 0;
        for (int p = 0; p < k; p++) {
            if (candidate[p] > result[p]) {
                better = 1;
                break;
            }
            else if (candidate[p] < result[p]) {
                break;
            }
        }
        if (better) {
            memcpy(result, candidate, sizeof(int)*k);
        }
        free(subseq1);
        free(subseq2);
        free(candidate);
    }
    return result;
}
