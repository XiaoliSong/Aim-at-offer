/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5

题目：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

分析：

扩展：
二叉树的前序遍历、中序遍历、后序遍历的非递归写法
*/

/*
//递归法
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL) return NULL;

        TreeNode* rightRes=Convert(pRootOfTree->right);
        if(rightRes!=NULL){
            //右链表不空，进行连接
            rightRes->left=pRootOfTree;
            pRootOfTree->right=rightRes;
        }
        
        TreeNode* leftRes=Convert(pRootOfTree->left);
        TreeNode* p=leftRes;
        while(p!=NULL&&p->right!=NULL){
            //找到左链表的尾
            p=p->right;
        }
        if(leftRes!=NULL){
            //左链表不空，进行连接
            p->right=pRootOfTree;
            pRootOfTree->left=p;
        }
        
        //左链表为空，返回pRootOfTree，否则返回leftRes
        return leftRes==NULL?pRootOfTree:leftRes;
    }
};
*/

/*
//改进的递归法，中序遍历leftEnd
class Solution {
public:
    TreeNode* leftEnd=NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL) return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL){
            //叶子节点，leftEnd为pRootOfTree，返回pRootOfTree
            leftEnd=pRootOfTree;
            return pRootOfTree;
        }
        
        TreeNode* leftRes=Convert(pRootOfTree->left);
        if(leftRes!=NULL){
            //左链表不空，进行连接
            leftEnd->right=pRootOfTree;
            pRootOfTree->left=leftEnd;
        }
        
        //左链表末尾为当前节点pRootOfTree
        leftEnd=pRootOfTree;
        //继续向右
        TreeNode* rightRes=Convert(pRootOfTree->right);
        if(rightRes!=NULL){
            rightRes->left=pRootOfTree;
            pRootOfTree->right=rightRes;
        }

        return leftRes==NULL?pRootOfTree:leftRes;
    }
};
*/

//非递归，类似于中序遍历
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> s;
        TreeNode* res=NULL;
        TreeNode* cur=pRootOfTree;
        TreeNode* pre=NULL;
        bool isFirst=true;
        while(cur!=NULL||!s.empty()){
            while(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            if(isFirst){
                res=cur;
                pre=cur;
                isFirst=false;
            }
            else{
                pre->right=cur;
                cur->left=pre;
                pre=cur;
            }
            cur=cur->right;
        }
        return res;
    }
};



/*
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
//前序遍历、先序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        s.push(cur);
        while(!s.empty()){
            cur=s.top();
            s.pop();
            res.push_back(cur->val);
            if(cur->right!=NULL) s.push(cur->right);
            if(cur->left!=NULL) s.push(cur->left);
        }
        return res;
    }
};
*/

/*
//Morris Traversal,前序遍历、先序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur=root;
        vector<int> res;
        while(cur) {
            if(!cur->left) {  //must first meet this node
                res.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode *pre=cur->left;
                while(pre->right!=NULL&& pre->right!=cur){
                    pre=pre->right;
                }
                if(pre->right!=NULL) {
                    pre->right=NULL;
                    cur=cur->right;
                }
                else {
                    res.push_back(cur->val);
                    pre->right=cur;
                    cur=cur->left;
                }
            }
        }
        return res;
    }
};
*/

/*
//中序遍历、中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur!=NULL||!s.empty()){
            while(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            res.push_back(cur->val);
            cur=cur->right;
        }
        return res;
    }
};
*/

/*
//后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        
        stack<TreeNode*> s;
        TreeNode* cur;
        s.push(root);
        while(!s.empty()){
            cur=s.top();
            s.pop();
            res.push_back(cur->val);
            if(cur->left!=NULL) s.push(cur->left);
            if(cur->right!=NULL) s.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/
