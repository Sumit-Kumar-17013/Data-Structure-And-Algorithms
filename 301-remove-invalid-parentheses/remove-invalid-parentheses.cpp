class Solution {
public:
    unordered_set<string> ans;

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void dfs(string s, int index, int leftRemove, int rightRemove) {

        // No more removals needed
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s))
                ans.insert(s);

            return;
        }

        for (int i = index; i < s.length(); i++) {

            // We only remove parentheses
            if (s[i] != '(' && s[i] != ')')
                continue;

            // Avoid duplicate removals
            if (i > index && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (s[i] == '(' && leftRemove > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);

                dfs(temp, i, leftRemove - 1, rightRemove);
            }

            // Remove ')'
            if (s[i] == ')' && rightRemove > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);

                dfs(temp, i, leftRemove, rightRemove - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals required
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};