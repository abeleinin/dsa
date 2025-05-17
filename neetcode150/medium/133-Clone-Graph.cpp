#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/**
 * \c IterativeBfsSolution
 * 
 * 1. Create a visited map from the old node to new node
 * 2. Use iterative BFS to traverse the graph checking if the neighbors have been visited
 * 3. Push all old neighbor nodes into the current nodes neighbor vector
 * 
 * Time  : O(|v|+|e|)
 * Space : O(|v|+|e|)
 */
class IterativeBfsSolution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
    
        unordered_map<Node*, Node*> visit;
        queue<Node*> q;
    
        visit[node] = new Node(node->val);
        q.push(node);
    
        while (!q.empty()) {
            auto curr = q.front(); 
            q.pop();
    
            for (Node* n : curr->neighbors) {
                if (visit.find(n) == visit.end()) {
                    visit[n] = new Node(n->val);
                    q.push(n);
                }
                visit[curr]->neighbors.push_back(visit[n]);
            }
        }
    
        return visit[node];
    }
};