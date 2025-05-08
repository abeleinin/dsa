#include <queue>
#include <vector>

using namespace std;

/**
 * \c KthLargest
 * 
 * 1. Use a min heap of size K
 * 2. Only store the K largest numbers
 * 3. Smallest values is always on top, which is also the Kth largest
 * 
 * Construstor : O(n log k)
 * add()       : O(log k)
 */
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > minh;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k; 
        for (int n : nums) {
            add(n);
        }
    }

    int add(int val) {
        minh.push(val);

        if (minh.size() > K) {
            minh.pop();
        }

        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */