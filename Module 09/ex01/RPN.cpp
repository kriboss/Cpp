#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>

RPN::RPN()
{
}

RPN::~RPN()
{
}

bool RPN::evaluate(const std::string &expr, int &result) const
{
    std::stack<int> st;
    std::istringstream ss(expr);
    std::string token;
    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            st.push(token[0] - '0');
            continue;
        }
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (st.size() < 2)
                return false;
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = 0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/")
            {
                if (b == 0)
                    return false;
                res = a / b;
            }
            st.push(res);
            continue;
        }
        return false;
    }
    if (st.size() != 1)
        return false;
    result = st.top();
    return true;
}
