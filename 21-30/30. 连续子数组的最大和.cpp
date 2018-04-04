/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163

题目：
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)。

分析：

*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res=INT_MIN;
        int cur=0;
        for(auto x:array){
            if(cur<=0){
                cur=x;
            }
            else{
                cur+=x;
            }
            if(res<cur) res=cur;
        }
        return res;
    }
};

/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res=INT_MIN;
        int curMax=INT_MIN;
        for(auto x:array){
            curMax=std::max(curMax+x,x);//错误！！curMax=INT_MIN 当x为负数时，加起来就正了
            res=std::max(res,curMax);
        }
        return res;
    }
};
*/