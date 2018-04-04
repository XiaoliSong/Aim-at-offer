/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd

题目：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

分析：
后序遍历序列的特点是末尾为中间的元素mid，可以根据mid把数组进行划分，前一部分都是小于mid，后一部分都大于mid；若后一部分夹杂小于mid，则不是。划分两部分后，分别对他们求是否又是子二叉搜索树

改进：
注意到left，right数组是原数组的子集，所以可以不构造left，right数组，使用原数组加下标表示left，right数组

非递归方法：
根为数组的末尾，去掉根之后，数组分为left，right两部分，left都是小于根，right都大于根
left，right都是二叉搜索树的后序遍历序列。right里的值都大于left里的值
所以right的末尾又可以看成是新根，而left仍然为新根的left，right-1为新根的right
由此循环

扩展：前序遍历，中序遍历？重建二叉搜索树？
前序遍历则首位为根，同样可以进行求解；中序遍历则需要找到一个下标（划分）使得左边都小于它，右边都大于它；

重建二叉树是可以的，但重建的二叉树可以不唯一


*/

//法1：构造left，right数组进行递归
/*
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;
        if(sequence.size()==1) return true;
        
        vector<int> left,right;
        left.reserve(sequence.size()/2);
        right.reserve(sequence.size()/2);
        int mid=sequence.back();
        
        int i=0;
        while(i<sequence.size()-1){
            if(sequence[i]<mid){
                left.push_back(sequence[i]);
                i++;
            }
            else break;
        }
        
        while(i<sequence.size()-1){
            if(sequence[i]<mid) return false;//中间插有<mid的数
            right.push_back(sequence[i]);
            i++;
        }
        
        if(left.size()>0&&right.size()>0) return VerifySquenceOfBST(left)&&VerifySquenceOfBST(right);
        else if(left.size()>0) return VerifySquenceOfBST(left);
        else if(right.size()>0) return VerifySquenceOfBST(right);
        else return true;
    }
};
*/

/*
//法2：不构造left，right数组，使用原数组加下标
class Solution {
public:
    bool judge(vector<int> &sequence,int left,int right){
        if(right<left) return false;
        if(right==left) return true;
        
        int midNum=sequence[right];
        int i=left;
        while(i<right){
            if(sequence[i]<midNum) i++;
            else break;
        }
        int midIndex=i;
        while(i<right){
            if(sequence[i]<midNum) return false;
            else i++;
        }
        if(midIndex-left>0&&right-midIndex>0)return judge(sequence,left,midIndex-1)&&judge(sequence,midIndex,right-1);
        else if(midIndex-left>0) return judge(sequence,left,midIndex-1);
        else if(right-midIndex>0) return judge(sequence,midIndex,right-1);
        return true;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        return judge(sequence,0,sequence.size()-1);
    }
};
*/

//非递归方法
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size=sequence.size();
        if(0==size)return false;
 
        int i=0;
        while(--size){
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};