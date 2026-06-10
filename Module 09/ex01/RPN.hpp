#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
public:
    RPN();
    ~RPN();

    bool evaluate(const std::string &expr, int &result) const;
};

#endif // RPN_HPP
