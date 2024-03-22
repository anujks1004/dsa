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

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;
        while(slow)
        {
            if(fast->val != slow->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;

    }
};