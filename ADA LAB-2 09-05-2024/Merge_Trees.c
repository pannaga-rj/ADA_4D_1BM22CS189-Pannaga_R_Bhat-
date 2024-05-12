/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    
    if(root1==NULL && root2==NULL)
        return NULL;
    if(root1 == NULL && root2!= NULL)
        return root2;
    if(root1!=NULL && root2==NULL)
        return root1;
    if(root1!=NULL && root2!=NULL)
        root1->val += root2->val;

    root1->right = mergeTrees(root1->right, root2->right);
    root1->left = mergeTrees(root1->left, root2->left);

    return root1;

}
