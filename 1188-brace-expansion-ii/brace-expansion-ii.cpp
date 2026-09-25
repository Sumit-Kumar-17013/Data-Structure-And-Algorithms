class Solution {
public:

    set<string> combine(set<string> a, set<string> b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> parse(string &s, int &i) {

        set<string> result;
        set<string> current;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; 

                set<string> inside = parse(s, i);

                i++;  
                current = combine(current.empty() ? set<string>{""} : current, inside);
            }

            else if (s[i] == ',') {
                result.insert(current.begin(), current.end());

                current.clear();
                i++;
            }

            else {

                set<string> letter = {string(1, s[i])};

                current = combine(
                    current.empty() ? set<string>{""} : current,
                    letter
                );

                i++;
            }
        }
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};