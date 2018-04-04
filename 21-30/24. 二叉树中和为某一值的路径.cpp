/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca

题目：
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

分析：
每次采用递归搜索左右子节点，expectNumber-当前val

扩展：
可以不到叶子节点结束，找出所有路径？

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root==NULL) return res;

        if(root->val==expectNumber&&root->left==NULL&&root->right==NULL){
            //叶子节点且val==expectNumber
            vector<int> tmp(1);
            tmp[0]=root->val;
            res.push_back(tmp);
            return res;
        }
        
        vector<vector<int> > leftRes=FindPath(root->left,expectNumber-root->val);
        vector<vector<int> > rightRes=FindPath(root->right,expectNumber-root->val);
        
        for(auto x:leftRes){
            x.insert(x.begin(),root->val);
            res.push_back(x);
        }
        for(auto x:rightRes){
            x.insert(x.begin(),root->val);
            res.push_back(x);
        }
        return res;
    }
};

/*
//可以不到叶子节点结束，找出所有路径
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        
        vector<vector<int> > leftRes=FindPath(root->left,expectNumber-root->val);
        vector<vector<int> > rightRes=FindPath(root->right,expectNumber-root->val);
        
        for(auto x:leftRes){
            x.insert(x.begin(),root->val);
            res.push_back(x);
        }
        for(auto x:rightRes){
            x.insert(x.begin(),root->val);
            res.push_back(x);
        }
        if(root->val==expectNumber){
            vector<int> tmp(1);
            tmp[0]=root->val;
            res.push_back(tmp);
        }
        return res;
    }
};
*/