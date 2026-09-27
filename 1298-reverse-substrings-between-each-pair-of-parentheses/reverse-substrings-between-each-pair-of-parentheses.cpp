class Solution {
public:
    string reverseParentheses(string s) {
        // TC = O(n^2)
        stack<string> st;
        string curr = "";

        for(int ch : s)
        {
            if(ch == '(')
            {
                st.push(curr);
                curr = "";
            }

            else if(ch == ')')
            {
                reverse(curr.begin() , curr.end());
                curr = st.top()  + curr;

                st.pop();
            }

            else
            {
                curr += ch;
            }
        }

        return curr;

    }
};
