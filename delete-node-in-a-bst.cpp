//https://leetcode.com/problems/delete-node-in-a-bst/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        if (root->val == key && root->left==NULL && root->right==NULL){ //this is a leaf node.
            delete root;
            return NULL;
        }
        if (root->val ==key){
            if (root->left!=NULL && root->right==NULL){ //this node only has one child. after delete this node, the parent node will connect with this child.
                TreeNode* temp = root->left;
                delete root;
                return root->left;
            }
            if (root->left==NULL && root->right!=NULL){//this node only has one child. after delete this node, the parent node will connect with this child.
                TreeNode* temp = root->right;
                delete root;
                return root->right;
            }
            if (root->left!=NULL && root->right!=NULL){//this node has two children. To keep BST, we need to find the minimum of the right subtree (or the maximum of the left subtree). Then, copy the minimum to this node, and then delete the minimum node on the right subtree. 
                TreeNode* temp = findmin(root->right);
                if (temp==NULL) return NULL;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            }
        } else{ //root->val !=key
            if (root->left ==NULL && root->right==NULL) return root;
            if (root->left) root->left = deleteNode(root->left, key);
            if (root->right) root->right = deleteNode(root->right, key);
        }
        return root;        
    }
    TreeNode* findmin(TreeNode* root){
        if (root==NULL) return root;
        while (root->left!=NULL) root=root->left;
        return root;
    }
};