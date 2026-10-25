#include <stdlib.h>

/*
// Definition provided by LeetCode:
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};
*/

#define MAX_NODES 101

struct Node* original[MAX_NODES];
struct Node* cloned[MAX_NODES];
int count = 0;

struct Node* dfs(struct Node* node) {
    if (node == NULL)
        return NULL;

    // Check if node is already cloned
    for (int i = 0; i < count; i++) {
        if (original[i] == node)
            return cloned[i];
    }

    // Create clone
    struct Node* copy = malloc(sizeof(struct Node));
    copy->val = node->val;
    copy->numNeighbors = node->numNeighbors;

    if (node->numNeighbors > 0) {
        copy->neighbors = malloc(
            node->numNeighbors * sizeof(struct Node*)
        );
    } else {
        copy->neighbors = NULL;
    }

    // Save mapping before DFS to handle cycles
    original[count] = node;
    cloned[count] = copy;
    count++;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        copy->neighbors[i] = dfs(node->neighbors[i]);
    }

    return copy;
}

struct Node* cloneGraph(struct Node* node) {
    count = 0;
    return dfs(node);
}