class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        queue<Node*> q;
        q.push(root);
        Node* node;

        while(!q.empty()){
            int total_size = q.size();

            for(int i = 0; i<total_size; i++){
                node = q.front();       q.pop();

                if(!q.empty() && (i+1 != total_size))       node->next = q.front();
                else                                        node->next = nullptr;

                if(node->left)      q.push(node->left);
                if(node->right)     q.push(node->right);
            }
        }
        return root;
    }
};