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
 * \c RecursiveSolution
 * 
 * 1. Check for the null case for both of the input lists
 * 2. Determine which values is smaller and make its next node 
 *    point to the recursive call
 * 3. Return the smaller list (intuitively just think of this as the
 *    first smaller node during the first pass of the function)
 * 
 * Time  : O(n+m)
 * Space : O(n+m)
 */
class RecursiveSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

/**
 * \c IterativeSolution
 * 
 * 1. Check for the null case for both of the input lists
 * 2. Determine the initial smaller value and create a pointer to it (head)
 * 3. Process the lists while both are not empty
 * 4. If a list still contains nodes, we know the remaining values are all 
 *    greater than our merged list, so we can simply point to the entire 
 *    list at the end
 * 
 * Time  : O(n+m)
 * Space : O(1)
 */
class IterativeSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
            
        ListNode* curr;
        if(list1->val < list2->val) {
            curr = list1;
            list1 = list1->next;
        } else {
            curr = list2;
            list2 = list2->next;
        }
        ListNode* head = curr;
    
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
    
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;
    
        return head;
    }
};