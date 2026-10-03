// Last updated: 10/3/2026, 6:52:02 PM
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int i = 0;
        std::set<std::string> resultSet = parseExpr(expression, i);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }

private:
    // expr = term (',' term)*
    std::set<std::string> parseExpr(const std::string& s, int& i) {
        std::set<std::string> res = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            std::set<std::string> nextTerm = parseTerm(s, i);
            res.insert(nextTerm.begin(), nextTerm.end());
        }

        return res;
    }

    // term = factor factor ... (concatenation)
    std::set<std::string> parseTerm(const std::string& s, int& i) {
        std::set<std::string> res = {""}; // multiplicative identity for cartesian product

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            std::set<std::string> factor = parseFactor(s, i);
            std::set<std::string> nextRes;

            for (const std::string& a : res) {
                for (const std::string& b : factor) {
                    nextRes.insert(a + b);
                }
            }
            res = std::move(nextRes);
        }

        return res;
    }

    // factor = single letter OR '{' expr '}'
    std::set<std::string> parseFactor(const std::string& s, int& i) {
        if (s[i] == '{') {
            i++; // skip '{'
            std::set<std::string> res = parseExpr(s, i);
            i++; // skip '}'
            return res;
        } else {
            std::string letter(1, s[i]);
            i++;
            return {letter};
        }
    }
};