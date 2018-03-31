/*
GitHub：https://github.com/XiaoliSong/Aim-at-offer
链接：https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca
题目：输入一个链表，反转链表后，输出链表的所有元素。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre=NULL;
        ListNode* cur=pHead;
        while(cur!=NULL){
            ListNode* curNext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=curNext;
        }
        return pre;
    }
};