// 二叉树
class TreeNode {

public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
    // 前序遍历
    void preorderTraversal() {
        cout << this->val;
        if(this->left != nullptr) {
            this->left->preorderTraversal();
        }
        if(this->right != nullptr) {
            this->right->preorderTraversal();
        }
    }

    // 中序遍历
    void inorderTraversal() {
        if(this->left != nullptr) {
            this->left->inorderTraversal();
        }
        cout << this->val << " ";
        if(this->right != nullptr) {
            this->right->inorderTraversal();
        }
    }

    // 后序遍历
    void postorderTraversal() {
        if(this->left != nullptr) {
            this->left->postorderTraversal();
        }
        if(this->right != nullptr) {
            this->right->postorderTraversal();
        }
        cout << this->val;
    }

    // 层序遍历
    void levelorderTraversal() {
        Queue<TreeNode*> queue;
        queue.offer(this);
        while(!queue.isEmpty()) {
            TreeNode* temp = queue.peek();
            cout << this->val;
            if(temp->left)
                queue.offer(this->left);
            if(temp->right)
                queue.offer(this->right);
            queue.poll();
        }
    }

    //获取叶子个数
    int getLeafCount(TreeNode* root, int count) {
        if(root == nullptr) return 0;
        if(!root->left && !root->right)
            return 1;
        return getLeafCount(root->left, count) + getLeafCount(root->right, count);
    }

    //获取高度
    int getDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    
    // 判断两棵树是否同构
    bool isIsomorphicTree(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if(root1 && root2) {
            if(root1->val == root2->val) {
                if((isIsomorphicTree(root1->left, root2->left) && isIsomorphicTree(root1->right, root2->right))
                || (isIsomorphicTree(root1->right, root2->left) && isIsomorphicTree(root1->left, root2->right)))
                    return true;
            }
        }
        return false;
    }
};