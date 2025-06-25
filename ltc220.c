typedef long long ll;

#define BUCKET_SIZE (valueDiff + 1)

typedef struct {
    ll key;
    ll value;
    bool used;
} Bucket;

int getBucketIndex(ll num, ll size) {
    return num < 0 ? (num + 1) / size - 1 : num / size;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    if (indexDiff <= 0 || valueDiff < 0) return false;

    int bucketCount = numsSize;
    Bucket* buckets = calloc(bucketCount, sizeof(Bucket));

    for (int i = 0; i < numsSize; i++) {
        ll remapped = (ll)nums[i] - INT_MIN;
        ll bucketId = getBucketIndex(remapped, BUCKET_SIZE);
        int hash = llabs(bucketId) % bucketCount;

        
        if (buckets[hash].used && buckets[hash].key == bucketId)
            return true;

        
        for (int j = -1; j <= 1; j++) {
            ll neighborId = bucketId + j;
            int h = llabs(neighborId) % bucketCount;
            if (buckets[h].used && buckets[h].key == neighborId) {
                if (llabs(remapped - buckets[h].value) <= valueDiff)
                    return true;
            }
        }

       
        buckets[hash].used = true;
        buckets[hash].key = bucketId;
        buckets[hash].value = remapped;

        if (i >= indexDiff) {
            ll old = (ll)nums[i - indexDiff] - INT_MIN;
            ll oldId = getBucketIndex(old, BUCKET_SIZE);
            int oldHash = llabs(oldId) % bucketCount;
            if (buckets[oldHash].used && buckets[oldHash].key == oldId) {
                buckets[oldHash].used = false;
            }
        }
    }

    free(buckets);
    return false;
}
