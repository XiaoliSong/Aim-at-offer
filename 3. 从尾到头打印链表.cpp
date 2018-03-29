/*
链接：https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035
题目：
输入一个链表，从尾到头打印链表每个节点的值。
分析：
方法可以有很多，列出几种：
1.使用栈，遍历单向链表，进栈操作；出栈存入数组
2.遍历使用数组保存，然后逆转数组
3.先遍历找出链表长度，然后再遍历插入数组（数组从后插入）
4.递归
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        int count=0;
        ListNode* tmp=head;
        while(tmp!=NULL){
            count++;
            tmp=tmp->next;
        }
        vector<int> res(count);
        tmp=head;
        while(tmp!=NULL){
            res[--count]=tmp->val;
            tmp=tmp->next;
        }
        return res;
    }
};