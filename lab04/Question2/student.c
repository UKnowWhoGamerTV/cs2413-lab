#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool mirrorRecurive(struct TreeNode* left, struct TreeNode* right)
{
  if(left == NULL && right == NULL)
    return true;

  else if((left == NULL && right != NULL) || (left != NULL && right == NULL))
    return false;

  if(left->val != right->val)
    return false;

  if(mirrorRecurive(left->left, right->right) && mirrorRecurive(left->right, right->left))
    return true;
  return false;
}

bool isSymmetric(struct TreeNode* root) {
  if(root == NULL)
    return true;
  struct TreeNode *left = root->left, *right = root->right;
  
  if(mirrorRecurive(left, right))
    return true;
  return false;
}