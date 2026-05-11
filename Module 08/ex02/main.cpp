#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
    std::cout << "=== MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nIterating forward:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nTesting with std::stack (copy constructor):" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Standard stack size: " << s.size() << std::endl;
    std::cout << "Standard stack top: " << s.top() << std::endl;

    std::cout << "\n=== Comparison Test with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_front();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "\nList iteration:" << std::endl;
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== Reverse Iterator Test ===" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(1);
    mstack2.push(2);
    mstack2.push(3);
    mstack2.push(4);
    mstack2.push(5);

    std::cout << "Reverse iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack2.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}
