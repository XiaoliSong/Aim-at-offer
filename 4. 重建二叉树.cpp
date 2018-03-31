/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
分析：
前序遍历结果的第一个一定是根节点，找出中序遍历结果中根节点所在位置，则可知道根节点的左右节点各有多少个节点，由此可以划分前序遍历结果分别属于左、右节点的的部分，中序遍历结果分别属于左、右节点的的部分，再进行递归求解
扩展：
1. 已知中序遍历结果、后序遍历结果，能否找出前序遍历结果或者重建二叉树
答案是可以，后序遍历结果的最后一个一定是根节点，找出中序遍历结果中根节点所在位置，则可知道根节点的左右节点各有多少个节点，由此可以划分后序遍历结果分别属于左、右节点的的部分，中序遍历结果分别属于左、右节点的的部分，再进行递归求解
2. 已知前序遍历结果、后序遍历结果，能否找出前序遍历结果或者重建二叉树
        1                   1
    2      3            2       3
  4      5   6            4   5    6
上面两个二叉树的前序遍历结果124356，后序遍历结果425631
所以无法唯一确定二叉树，也就无法进行重建
    
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0||vin.size()==0){
            return NULL;
        }
        vector<int> newLeftVin;
        vector<int> newRightVin;
        int i=0;
        while(vin[i]!=pre[0]){
            newLeftVin.push_back(vin[i]);
            i++;
        }
        int midIndex=i;
        i++;
        while(i<vin.size()){
            newRightVin.push_back(vin[i]);
            i++;
        }
        
        vector<int> newLeftPre;
        vector<int> newRightPre;
        i=1;
        while(i<=midIndex){
            newLeftPre.push_back(pre[i]);
            i++;
        }
        while(i<pre.size()){
            newRightPre.push_back(pre[i]);
            i++;
        }
        
        struct TreeNode* res=new TreeNode(pre[0]);
        res->left=reConstructBinaryTree(newLeftPre,newLeftVin);
        res->right=reConstructBinaryTree(newRightPre,newRightVin);
        return res;
    }
};