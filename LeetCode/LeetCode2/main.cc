/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newNode = new ListNode(0);
        ListNode* Node=newNode;
        int up=0;
        int sum=0;
        while(l1 || l2){
            const int left=l1==nullptr?0:l1->val;
            const int right=l2==nullptr?0:l2->val;
            sum=(left+right+up)%10;
            up=(left+right+up)/10;
            Node->next=new ListNode(sum);
            Node=Node->next;
            l1=l1==nullptr?nullptr:l1->next;
            l2=l2==nullptr?nullptr:l2->next;
        }
        if(up>0){
            Node->next=new ListNode(up);
        }
        return newNode->next;
    }
};
