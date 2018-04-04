/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/6a296eb82cf844ca8539b57c23e6e9bf

题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

分析：


*/

/*
//排序法，复杂度O(N*LogN)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size()==0||k>input.size()||k<=0) return res;
        
        sort(input.begin(),input.end());
        
        res.reserve(k);
        for(int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
};
*/


/*
//最大堆（优先队列）实现，复杂度O(NLogK)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k<=0||k>input.size()||input.size()==0) return vector<int>();
        
        int top;
        //std::priority_queue<int, std::vector<int>, greater<int>> q;
        priority_queue<int> q;
        for(auto x:input){
            if(q.size()<k){
                q.push(x);
                top=q.top();
            }
            else if(top>x){
                q.pop();
                q.push(x);
                top=q.top();
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
*/

/*
multiset红黑树实现，复杂度O(NLogK)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k<=0||k>input.size()||input.size()==0) return vector<int>();
        
        multiset<int, greater<int> > leastNums;
        
        for(auto x:input)
        {
            if(leastNums.size()<k){
                leastNums.insert(x);
            }
            else if(*(leastNums.begin())>x){
                leastNums.erase(leastNums.begin());
                leastNums.insert(x);
            }
        }
                    
        return vector<int>(leastNums.begin(),leastNums.end());
    }
};
*/

//划分法，复杂度O(N)
class Solution {
public:
    int partition(vector<int> &arr,int left,int right){
        int i=left+1,j=right;
        while(true){
            while(arr[i]<=arr[left]&&i<j) i++;
            while(arr[j]>=arr[left]) j--;
            if(i>=j) break;
            swap(arr[i],arr[j]);
        }
        swap(arr[left],arr[j]);
        return j;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k<=0||k>input.size()||input.size()==0) return vector<int>();

        int left=0,right=input.size()-1;
        int index=partition(input,0,input.size()-1);
        while(true){
            if(index==k||index==k-1) break;
            else if(index>k) {
                right=index-1;
            }
            else {
                left=index+1;
            }
            index=partition(input,left,right);
        }
        
        return vector<int>(input.begin(),input.begin()+k);
    }
};