class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char ch : s) {
            // Push everything except closing bracket
            if (ch != ']') {
                st.push(ch);
            } else {
                // Step 1: Get the substring inside []
                string strToRepeat = "";
                while (!st.empty() && st.top() != '[') {
                    strToRepeat += st.top();
                    st.pop();
                }
                reverse(strToRepeat.begin(), strToRepeat.end());

                // Step 2: Pop the '['
                if (!st.empty()) st.pop();

                // Step 3: Get the number before '['
                string numberStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numberStr += st.top();
                    st.pop();
                }
                reverse(numberStr.begin(), numberStr.end());
                int repeatCount = stoi(numberStr);

                // Step 4: Repeat the string and push back
                string expanded = "";
                for (int i = 0; i < repeatCount; i++) {
                    expanded += strToRepeat;
                }
                for (char c : expanded) {
                    st.push(c);
                }
            }
        }

        // Step 5: Build final result
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};