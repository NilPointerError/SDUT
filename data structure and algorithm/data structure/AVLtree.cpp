#include <bits/stdc++.h>
using namespace std;

// 二叉平衡树
class AVLTreeNode {

public:
    int val;
    int height;// 高度
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode() : val(0), left(nullptr), right(nullptr) {}
    AVLTreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
    AVLTreeNode(int x, AVLTreeNode *left, AVLTreeNode *right) : val(x), left(left), right(right) {}
};

class AVLTree {

public:
    AVLTreeNode* _root;
    AVLTree(AVLTreeNode* root=nullptr): _root(root) {};
    // 右旋
    AVLTreeNode* rightRotate(AVLTreeNode* cur) {
        AVLTreeNode* leftNode = cur->left;
        cur->left = leftNode->right;
        leftNode->right = cur;
        cur->height = max((cur->left != nullptr ? cur->left->height : 0), (cur->right != nullptr ? cur->right->height : 0)) + 1;//更新高度
    	leftNode->height = max((leftNode->left != nullptr ? leftNode->left->height : 0), (leftNode->right != nullptr ? leftNode->right->height : 0)) + 1;//更新高度
        return leftNode;
    }
    // 左旋
    AVLTreeNode* leftRotate(AVLTreeNode* cur) {
        AVLTreeNode* rightNode = cur->right;
        cur->right = rightNode->left;
        rightNode->left = cur;
        cur->height = max((cur->left != nullptr ? cur->left->height : 0), (cur->right != nullptr ? cur->right->height : 0)) + 1;//更新高度
    	rightNode->height = max((rightNode->left != nullptr ? rightNode->left->height : 0), (rightNode->right != nullptr ? rightNode->right->height : 0)) + 1;//更新高度
        return rightNode;
    }
    
    AVLTreeNode* maintain(AVLTreeNode* cur) {
        if(cur == nullptr) return nullptr;
        int leftHeight = cur->left != nullptr ? cur->left->height : 0;//计算出cur左树的高度
    	int rightHeight = cur->right != nullptr ? cur->right->height : 0;//计算出cur右树的高度
    	if (abs(leftHeight - rightHeight) > 1) {//出现不平衡
            // 左子树高度 > 右子树高度
            if(leftHeight > rightHeight) {
                // 比较左子树的左右子树
                int leftLeftHeight = cur->left != nullptr && cur->left->left != nullptr ? cur->left->left->height : 0;
        		int leftRightHeight = cur->left != nullptr && cur->left->right != nullptr ? cur->left->right->height : 0;
                // LL 右旋
                if(leftLeftHeight >= leftRightHeight) {
                    cur = rightRotate(cur);
                } else {
                    // LR 左子树先左旋 根节点再右旋
                    cur->left = leftRotate(cur->left);
                    cur = rightRotate(cur);
                }
            } else {
                int rightLeftHeight = cur->right != nullptr && cur->right->left != nullptr ? cur->right->left->height: 0;
        		int rightRightHeight = cur->right != nullptr && cur->right->right != nullptr ? cur->right->right->height : 0;
                // RR 左旋
				if(rightRightHeight >= rightLeftHeight) {
                    cur = leftRotate(cur);            
                } else {
                    // RL 右子树先右旋 根节点再左旋
                    cur->right = rightRotate(cur->right);
                    cur = leftRotate(cur);
                }
            }
    	}
        return cur;
    }
    
    AVLTreeNode* add(AVLTreeNode* cur, int val) {
        if(cur == nullptr) {
            return new AVLTreeNode(val);
        } else if(val < cur->val) {
            cur->left = add(cur->left, val);
        } else {
            cur->right = add(cur->right, val);
        }
        // 边插入边比较 寻找最小不平衡子树的根节点进行调整
        // 通过旋转最小失衡树来使整棵树达到平衡
        cur->height = max(cur->left != nullptr ? cur->left->height : 0, cur->right != nullptr ? cur->right->height : 0)+1;//重新计算高度
        cur = maintain(cur);
        return cur;
    }
    
    bool insert(int val) {
        _root = add(_root, val);
        return true;
    }
    
};



int main()
{
    int n;
    cin >> n;
    AVLTree* tree = new AVLTree();
    int val;
    for (int i = 0; i < n; i++) {
        /* code */
        cin >> val;
        tree->insert(val);
    }
	// 输出AVL根节点值
    cout << tree->_root->val << endl;
    return 0;
}

/*

  代码参考: https://blog.csdn.net/qq_56999918/article/details/122759059?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-122759059-blog-125130608.235%5Ev27%5Epc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-122759059-blog-125130608.235%5Ev27%5Epc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=5

*/