/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    int key;
    int freq;
    UT_hash_handle hh;
} FreqEntry;

typedef struct BucketNode {
    int val;
    struct BucketNode *next;
} BucketNode;

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    FreqEntry *map = NULL;

    int i = 0;
    for (i = 0; i < numsSize; i++) {
        int x = nums[i];
        FreqEntry *e = NULL;
        HASH_FIND_INT(map, &x, e);
        if (e == NULL) {
            e = (FreqEntry *)malloc(sizeof(FreqEntry));
            e->key = x;
            e->freq = 1;
            HASH_ADD_INT(map, key, e);
        } else {
            e->freq = e->freq + 1;
        }
    }

    BucketNode **buckets = (BucketNode **)calloc(numsSize + 1, sizeof(BucketNode *));

    FreqEntry *cur = NULL;
    FreqEntry *tmp = NULL;
    HASH_ITER(hh, map, cur, tmp) {
        int f = cur->freq;
        BucketNode *node = (BucketNode *)malloc(sizeof(BucketNode));
        node->val = cur->key;
        node->next = buckets[f];
        buckets[f] = node;
    }

    int *result = (int *)malloc(sizeof(int) * k);
    int out = 0;

    for (i = numsSize; i >= 1 && out < k; i--) {
        BucketNode *node = buckets[i];
        while (node != NULL && out < k) {
            result[out] = node->val;
            out = out + 1;
            node = node->next;
        }
    }

    for (i = 0; i <= numsSize; i++) {
        BucketNode *node = buckets[i];
        while (node != NULL) {
            BucketNode *next = node->next;
            free(node);
            node = next;
        }
    }
    free(buckets);

    HASH_ITER(hh, map, cur, tmp) {
        HASH_DEL(map, cur);
        free(cur);
    }

    *returnSize = k;
    return result;
}
