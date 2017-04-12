#include<climits>
#include <assert.h>

#define NULL nullptr
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isValid(TreeNode* node, long minv, long maxv) {
    if(node == NULL) return true;
    if(node->val <= minv || node->val >= maxv) return false;

    return isValid(node->left, minv, node->val) &&
           isValid(node->right, node->val,maxv);
}

bool isValidBST(TreeNode* root) {
    if(root == NULL) return true;
    return isValid(root, LONG_MIN, LONG_MAX);
}


int bstmain() {
    TreeNode l(1);
    TreeNode r(4);
    TreeNode root(2, &l, &r);

    assert(isValidBST(&root));

    TreeNode root2(2147483647, NULL, NULL);
    assert(isValidBST(&root2));
}
