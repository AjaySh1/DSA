/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return head;
        ListNode*p1=head;
        ListNode*p2=head->next;
        while(p1->next&&p1->next->next)
        {
            ListNode*temp=p1->next->next;
            ListNode*cur=p1->next;
            p1->next=temp;
            cur->next=temp->next;
            p1=temp;
        }
        p1->next=p2;
        return head;
    }
};