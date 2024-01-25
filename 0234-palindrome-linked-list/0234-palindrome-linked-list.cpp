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
   ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // Base case
        if(curr == NULL){
            return prev;
        }

        // Ek case hum solve kar lete hai
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // Ab baki ka recursion solve kr lega
        return reverseUsingRecursion(prev, curr);
    }

    bool compareList(ListNode* head, ListNode* head2){
         while(head2 != NULL){
            if(head->val != head2->val){
                return false;
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return true; 
    }
    
    bool isPalindrome(ListNode* head) {
        // Step 1: Break linked list into 2 halfs
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Step 2: Reverse second half of linked list
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr); 

        // Step 3: Compare first half with reversed second half  
        bool ans = compareList(head, head2);  
        return ans;
    }
};