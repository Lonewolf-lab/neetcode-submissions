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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;

        while(curr1 ||  curr2 || carry){
            int val1 = 0, val2 = 0;
            if(curr1) val1 = curr1->val;
            if(curr2) val2= curr2->val;

            int sum = val1 + val2 + carry;

            int digit = sum%10;
            carry = sum/10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }
        return dummy->next;
    }
};