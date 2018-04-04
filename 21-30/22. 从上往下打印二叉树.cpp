
/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701

题目：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

分析：
（1）当前链表存有root节点
（2）遍历当前链表的节点，节点不空，则添加到结果序列，且其左右节点添到下次的链表；
（3）遍历完成则当前链表变成下次的链表
（4）当前链表不为空，转（2）
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        
        list<TreeNode*> curList;
        curList.push_back(root);
        while(!curList.empty()){
            list<TreeNode*> nextList;
            for(auto x:curList){
                if(x!=NULL){
                    //节点不空，则添加到结果序列，且左右节点添到下次的链表
                    res.push_back(x->val);
                    nextList.push_back(x->left);
                    nextList.push_back(x->right);
                }
            }
            curList=nextList;
        }
        return res;
    }
};