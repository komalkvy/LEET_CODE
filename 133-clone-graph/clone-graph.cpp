/*
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
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        // If the original node is null, the clone is null.
        if (node == NULL) return NULL;

        // If the node is already cloned, return the existing clone.
        // This handles cycles and prevents infinite loops.
        if (mp.count(node)) return mp[node];

        // Create a new clone for the current node.
        Node* clone = new Node(node->val);
        // Map the original node to its clone.
        mp[node] = clone;

        // Recursively clone all neighbors of the original node
        // and add them to the clone's neighbor list.
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};