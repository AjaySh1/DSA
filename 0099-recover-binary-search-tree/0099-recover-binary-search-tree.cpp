class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr; 
    TreeNode*cur=nullptr;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

   
        if (first == nullptr && prev && prev->val >= root->val) {
            first = prev;
            cur=root;
        }
        if (first != nullptr && prev->val >= root->val) {
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

      
        if (first && second) {
            swap(first->val, second->val);
        }
        else 
        swap(first->val,cur->val);
    }
};
