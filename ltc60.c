char* getPermutation(int n, int k) {
    int fact[10];
    fact[0] = 1;


    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int nums[10];
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    char* ans = (char*)malloc(n + 1);
    ans[n] = '\0';

    k = k - 1; 

    for (int i = 0; i < n; i++) {
        int idx = k / fact[n - i - 1];
        ans[i] = nums[idx] + '0';

        for (int j = idx; j < n - i - 1; j++) {
            nums[j] = nums[j + 1];
        }

        k %= fact[n - i - 1];
    }

    return ans;
}
