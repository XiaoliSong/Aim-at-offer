/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88
题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）。
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL) return false;
        
        bool res=false;
        if(pRoot1->val==pRoot2->val) {
            //当前val相等，则判断左右子节点是否是子树关系
            res=isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right);
        }
        if(res==true) return res;
        
        //判断pRoot1的左子节点是否含pRoot2
        res=HasSubtree(pRoot1->left,pRoot2);
        if(res==true) return res;
        //判断pRoot1的右子节点是否含pRoot2
        res=HasSubtree(pRoot1->right,pRoot2);
        return res;
    }
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2==NULL) {
            //pRoot2为空，说明pRoot1包含完整的pRoot2
            return true;
        }
        if(pRoot1==NULL) {
            //pRoot2不为空，而pRoot1为空，则pRoot1肯定不含完整的pRoot2
            return false;
        }
        if(pRoot1->val!=pRoot2->val) {
            //值不等，肯定不是子结构
            return false;
        }
        //继续判断左右子节点是否同时满足子结构
        return isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right);
    }
};