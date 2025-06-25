long long countPairs(long long* nums1, int n1, long long* nums2, int n2, long long mid) {
    long long count = 0;
    for (int i = 0; i < n1; ++i) {
        if (nums1[i] < 0) {
            int l = 0, r = n2 - 1, pos = n2;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums1[i] * nums2[m] <= mid) {
                    pos = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            count += n2 - pos;
        } else {
            int l = 0, r = n2 - 1, pos = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums1[i] * nums2[m] <= mid) {
                    pos = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            count += pos + 1;
        }
    }
    return count;
}

int compare(const void* a, const void* b) {
    long long diff = (*(long long*)a) - (*(long long*)b);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

long long kthSmallestProduct(int* a1, int a1Size, int* a2, int a2Size, long long k) {
    long long nums1[a1Size], nums2[a2Size];
    for (int i = 0; i < a1Size; i++) nums1[i] = (long long)a1[i];
    for (int i = 0; i < a2Size; i++) nums2[i] = (long long)a2[i];

    qsort(nums1, a1Size, sizeof(long long), compare);
    qsort(nums2, a2Size, sizeof(long long), compare);

    long long left = -1e10, right = 1e10, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (countPairs(nums1, a1Size, nums2, a2Size, mid) >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
