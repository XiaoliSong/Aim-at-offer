/*
链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?from=relative
题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
分析：
从二维数组左下角往右上角搜索，遇到如果当前值小于target，则往上搜索；大于target则往右
复杂度：最好O(1)，最差O(M+N),平均(M+N)/2
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()<=0) return false;
        int rowCount=array.size();
        int colCount=array[0].size();
        int i,j;
        for(i=rowCount-1,j=0;i>=0&&j<colCount;){
            if(target<array[i][j]){
                i--;
            }
            else if(target>array[i][j]){
                 j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};