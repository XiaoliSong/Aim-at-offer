/*
链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
题目：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
分析：
如果采用遍历查找需要O(N)时间复杂度
如果采用差值（第一个左边大于右边）查找的话，最好O(1)，最差O(N)，平均(N/2)
如果采用部分二分搜索，最好Log(N)，最差O(N)
rotateArray[mid]=rotateArray[high]时无法二分搜索
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0) return 0;
        int low=0,high=rotateArray.size()-1;
        while(low<high){ 
            int mid =(low+high)/2;
            if(rotateArray[mid]<rotateArray[high]){
                high=mid;
            }
            else if(rotateArray[mid]>rotateArray[high]){
                low=mid+1;
            }
            else{
                high=high-1;
            }
        }
        return rotateArray[low];
    }
};