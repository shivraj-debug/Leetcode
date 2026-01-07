/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        totalSum=sum(root);

        prod(root);

        return maxProd%MOD;
    }


    long long sum(TreeNode* root){
        if(!root) return 0;

        return root->val + sum(root->left) + sum(root->right);
    }

    long long prod(TreeNode* root){
        if(!root) return 0;

        long long prods=root->val + prod(root->left) + prod(root->right);

        long long totalProd=prods*(totalSum-prods);
        
        maxProd=max(totalProd,maxProd);

        return prods;

    }
};