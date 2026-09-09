#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>
#include <limits>

static bool calculate(char operation, long left, long right, long &result)
{
    const long maximum = std::numeric_limits<long>::max();
    const long minimum = std::numeric_limits<long>::min();
    if (operation == '+')
    {
        if ((right > 0 && left > maximum - right)
            || (right < 0 && left < minimum - right))
            return false;
        result = left + right;
    }
    else if (operation == '-')
    {
        if ((right < 0 && left > maximum + right)
            || (right > 0 && left < minimum + right))
            return false;
        result = left - right;
    }
    else if (operation == '*')
    {
        if (left != 0 && right != 0)
        {
            if ((left == -1 && right == minimum) || (right == -1 && left == minimum))
                return false;
            if ((left > 0 && right > 0 && left > maximum / right)
                || (left > 0 && right < 0 && right < minimum / left)
                || (left < 0 && right > 0 && left < minimum / right)
                || (left < 0 && right < 0 && left < maximum / right))
                return false;
        }
        result = left * right;
    }
    else
    {
        if (right == 0 || (left == minimum && right == -1))
            return false;
        result = left / right;
    }
    return true;
}

RPN::RPN()
{
}

RPN::~RPN()
{
}

bool RPN::evaluate(const std::string &expr, long &result) const
{
    std::stack<long> st;
    std::istringstream ss(expr);
    std::string token;
    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            st.push(token[0] - '0');
            continue;
        }
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (st.size() < 2)
                return false;
            long b = st.top(); st.pop();
            long a = st.top(); st.pop();
            long res = 0;
            if (!calculate(token[0], a, b, res))
                return false;
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
