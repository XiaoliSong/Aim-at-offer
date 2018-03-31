/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/564f4c26aa584921bc75623e48ca3011
题目：操作给定的二叉树，将其变换为源二叉树的镜像。

*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        //交换左右节点
        TreeNode *tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        //继续对左右节点镜像
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};