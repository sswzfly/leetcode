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
        ListNode* head1 = NULL;
        while(l1) {
            ListNode* p = new ListNode(l1->val);
            p->next = head1;
            head1 = p;
            l1 = l1->next;
        }
        ListNode* head2 = NULL;
        while(l2) {
            ListNode* p = new ListNode(l2->val);
            p->next = head2;
            head2 = p;
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = NULL;
        while(head1 || head2) {
            int sum = 0;
            if(head1) {
                sum += head1->val;
                head1 = head1->next;
            }
            if(head2) {
                sum += head2->val;
                head2 = head2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* p = new ListNode(sum);
            p->next = head;
            head = p;
        }
        if(carry) {
            ListNode* p = new ListNode(carry);
            p->next = head;
            head = p;
        }
        return head;
    }
};
