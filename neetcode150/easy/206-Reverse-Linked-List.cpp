#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/**
 * \c IterativeSolution
 * 
 * 1. Temporarily store the next node (curr->next)
 * 2. Set curr->next to previous
 * 3. Set previous to the current node
 * 4. Set current to the temporary node (next)
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class IterativeSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/**
 * \c RecursiveSolution
 * 
 * 1. Define a base case
 * 2. `head->next->next = head` reverses the link between head and head->next as the stack unwinds
 * 3. Cut the forward link with `head->next = nullptr`
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class RecursiveSolution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
    
        ListNode* revHead = reverseList(head->next);
    
        head->next->next = head;
        head->next = nullptr;
    
        return revHead;
    }
};