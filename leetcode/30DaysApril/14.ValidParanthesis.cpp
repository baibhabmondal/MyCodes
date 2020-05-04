/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

class Solution
{
  public:
    unordered_map<string, bool> m;

    bool checkValidString(string s)
    {
        return solve(0, s, 0);
    }

    bool solve(int i, string s, int c)
    {

        string temp = "";
        temp += '0' + i;
        temp += ',';
        temp += '0' + c;
        cout << temp << '\n';
        if (m.find(temp) != m.end())
        {
            return m[temp];
        }
        bool ans = false;
        if (c < 0)
            return false;
        if (i >= s.length() && c == 0)
        {
            return m[temp] = true;
        }
        else if (i >= s.length())
        {
            return m[temp] = false;
        }
        if (s[i] == ')' && c == 0)
            return m[temp] = false;

        while (i < s.length() && s[i] == '(')
        {
            c++;
            i++;
        }
        if (i >= s.length())
        {
            return m[temp] = false;
        }
        while (i < s.length() && s[i] == ')')
        {
            c--;
            i++;
            if (c < 0)
                return m[temp] = false;
        }
        if (i == s.length() && c == 0)
            return m[temp] = true;
        else if (i == s.length())
            return m[temp] = false;
        if (s[i] == '*')
        {
            ans = solve(i + 1, s, c) || solve(i + 1, s, c + 1) || solve(i + 1, s, c - 1);
        }
        else
        {
            ans = solve(i, s, c);
        }
        return m[temp] = ans;
    }
};