class NestedIterator {
private:    
    stack<NestedInteger> stack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stack.push(nestedList[i]);
        }        
    }
    
    int next() {
        int result = stack.top().getInteger();
        stack.pop();
        return result;        
    }
    
    bool hasNext() {
        while (!stack.empty()) {
            NestedInteger current = stack.top();
            if (current.isInteger()) {
                return true;
            }
            stack.pop();
            vector<NestedInteger> nestedList = current.getList();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stack.push(nestedList[i]);
            }
        }
        return false;        
    }
};