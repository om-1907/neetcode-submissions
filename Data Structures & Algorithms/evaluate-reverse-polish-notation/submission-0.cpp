class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& i : tokens) {

            if (i != "+" && i != "-" && i != "*" && i != "/") {
                st.push(stoi(i));
            }
            else {
                int top1 = st.top();
                st.pop();

                int top2 = st.top();
                st.pop();

                if (i == "+")
                    st.push(top2 + top1);
                else if (i == "-")
                    st.push(top2 - top1);
                else if (i == "*")
                    st.push(top2 * top1);
                else
                    st.push(top2 / top1);
            }
        }

        return st.top();
    }
};