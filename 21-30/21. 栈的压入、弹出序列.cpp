/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106

题目：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

分析：
用栈保存进栈内容，当栈顶和出栈序列头相等时一直出栈、出栈序列头后移。最终栈空则是出栈序列。

*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(popV.size()!=pushV.size()) return false;
        if(popV.size()==0) return true;
        
        stack<int> s;
        for(int i=0,j=0;i<pushV.size();i++){
            s.push(pushV[i]);
            while(j<popV.size()&&s.top()==popV[j]){
                //栈顶和已知出栈栈顶相等则出栈
                s.pop();
                j++;
            }
        }
        return s.empty();
        
        /*
        //也可行，从出栈序列的后往前看
        //栈s保存进栈的内容
        int i=pushV.size()-1;
        int j=popV.size()-1;
        while(i>=0&&j>=0){
            if(popV[j]==pushV[i]){
                //进栈序列的尾和出栈序列的尾相等，抵消
                j--;
                i--;
            }
            else if(s.empty()){
                //栈空，进栈内容为出栈序列的尾popV[j]
                s.push(popV[j]);
                j--;
            }
            else if(s.top()==pushV[i]){
                //栈顶和pushV[i]相等，进栈序列的尾前移，栈出栈
                s.pop();
                i--;
            }
            else{
                //加入出栈序列的尾popV[j]
                s.push(popV[j]);
                j--;
            }
        }
        
        //可能还未到达进栈序列头，看是否能全部出栈完全
        for(int k=i;k>=0;k--){
            if(s.top()==pushV[k]){
                s.pop();
            }
            else{
                return false;
            }
        }
        return s.empty();
        */
    }
};