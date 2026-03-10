/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int height(struct TreeNode* root)
{   
    if(root != NULL)
        return 1 + max(height(root->left), height(root->right));
    return 0;
}

bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
        return true;

    int lheight = 0, rheight = 0;
    if(root->left != NULL)
        lheight = height(root->left);

    if(root->right != NULL)
        rheight = height(root->right);
    printf("L:%d R:%d   ", lheight, rheight);
    if((lheight - rheight) >= 2 || (lheight - rheight) <= -2)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}

int isBST(struct TreeNode* root, int min, int max) 
{
    if (root == NULL)
        return 1;

    if ((root->val <= min && min != INT_MIN) || (root->val >= max && max != INT_MAX))
        return 0;

    return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

bool isAVL(struct TreeNode* root) 
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    int min = INT_MIN, max = INT_MAX;
    if(isBalanced(root) && isBST(root, min, max))
        return true;
    return false;
}
