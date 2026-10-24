/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void inorder(struct TreeNode* root, int* prev, int* hasPrev,
             int* count, int* maxCount, int* modes, int* size) {
    if (root == NULL) return;

    inorder(root->left, prev, hasPrev, count, maxCount, modes, size);

    if (*hasPrev && root->val == *prev) {
        (*count)++;
    } else {
        *prev = root->val;
        *hasPrev = 1;
        *count = 1;
    }

    if (*count > *maxCount) {
        *maxCount = *count;
        *size = 0;
        modes[(*size)++] = root->val;
    } else if (*count == *maxCount) {
        modes[(*size)++] = root->val;
    }

    inorder(root->right, prev, hasPrev, count, maxCount, modes, size);
}
int* findMode(struct TreeNode* root, int* returnSize) {
    int* modes = malloc(10000 * sizeof(int));
    int prev = 0 , hasPrev = 0;
    int count = 0 , MaxCount = 0 , size = 0;

    inorder(root,&prev,&hasPrev,&count,&MaxCount,modes,&size);

    *returnSize = size;
    return modes;

}