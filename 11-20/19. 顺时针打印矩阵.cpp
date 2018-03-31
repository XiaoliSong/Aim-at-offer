/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/564f4c26aa584921bc75623e48ca3011
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;

        //x1,y1,x2,y2代表着要打印的矩形框
        int x1=0,y1=0,x2=matrix[0].size()-1,y2=matrix.size()-1;
        res.reserve(x2*y2);
        while(x1<=x2&&y1<=y2){
            for(int i=x1;i<=x2;i++){
                res.push_back(matrix[y1][i]);
            }
            for(int i=y1+1;i<=y2;i++){
                res.push_back(matrix[i][x2]);
            }
            if(y1!=y2){
                //避免横排
                for(int i=x2-1;i>=x1;i--){
                    res.push_back(matrix[y2][i]);
                }
            }
            if(x1!=x2){
                //避免竖列
                for(int i=y2-1;i>y1;i--){
                    res.push_back(matrix[i][x1]);
                }
            }
            x1++;
            x2--;
            y1++;
            y2--;
        }
        return res;
    }
};