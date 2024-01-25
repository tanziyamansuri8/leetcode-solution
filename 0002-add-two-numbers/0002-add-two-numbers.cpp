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
   ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    int getLength(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        ListNode* temp = head;
        int ans = 0;
        while (temp) {
            ans++;
            temp = temp->next;
        }
        return ans;
    }
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    int a = getLength(l1);
    int b = getLength(l2);
    if (a < b) {
        swap(l1, l2);
    }
    ListNode* l = l1;
    int carry = 0;
    while (l2 != nullptr) {
        int sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        if (l1->next == nullptr && (l2->next != nullptr || carry != 0)) {
            l1->next = new ListNode(0);
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr && carry != 0) {
        int sum = l1->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;

        if (l1->next == nullptr && carry != 0) {
            l1->next = new ListNode(carry);
            break;
        }

        l1 = l1->next;
    }
    if (carry != 0) {
        l1->next = new ListNode(carry);
    }
    // return reverse(l);
    return (l);
}
};