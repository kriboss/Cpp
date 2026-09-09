#include "PmergeMe.hpp"
#include <vector>
#include <deque>

// Helper: binary insert into container (vector)
static void binaryInsertVector(std::vector<int> &res, int value)
{
    if (res.empty()) { res.push_back(value); return; }
    int left = 0, right = (int)res.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (value <= res[mid]) right = mid;
        else left = mid + 1;
    }
    res.insert(res.begin() + left, value);
}

// Helper: binary insert into deque
static void binaryInsertDeque(std::deque<int> &res, int value)
{
    if (res.empty()) { res.push_back(value); return; }
    int left = 0, right = (int)res.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (value <= res[mid]) right = mid;
        else left = mid + 1;
    }
    res.insert(res.begin() + left, value);
}

// Generate Jacobsthal numbers up to limit (exclusive)
static std::vector<int> jacobsthalUpTo(int limit)
{
    std::vector<int> J;
    if (limit <= 0) return J;
    J.push_back(1);
    J.push_back(3);
    while (J.back() < limit)
    {
        int sz = (int)J.size();
        int next = J[sz-1] + 2 * J[sz-2];
        J.push_back(next);
    }
    return J;
}

static std::vector<int> insertionOrder(int count)
{
    std::vector<int> order;
    if (count <= 0)
        return order;
    order.push_back(0);
    std::vector<int> jacobsthal = jacobsthalUpTo(count);
    int previous = 1;
    for (std::size_t group = 1; group < jacobsthal.size(); ++group)
    {
        int upper = jacobsthal[group];
        if (upper > count)
            upper = count;
        for (int index = upper; index > previous; --index)
            order.push_back(index - 1);
        previous = jacobsthal[group];
        if (previous >= count)
            break;
    }
    return order;
}

void sortVector(std::vector<int> &v)
{
    if (v.empty()) return;
    int n = (int)v.size();
    // Pair elements
    std::vector<int> big; big.reserve((n+1)/2);
    std::vector<int> small; small.reserve(n/2 + 1);
    int i = 0;
    for (; i + 1 < n; i += 2)
    {
        int a = v[i];
        int b = v[i+1];
        if (a < b) { big.push_back(b); small.push_back(a); }
        else { big.push_back(a); small.push_back(b); }
    }
    bool has_last = false;
    int last_val = 0;
    if (i < n) { has_last = true; last_val = v[i]; }

    // Sort big elements
    sortVector(big);

    // Build insertion order using Jacobsthal sequence
    int m = (int)big.size();
    std::vector<int> order = insertionOrder(m);

    // Initialize result with sorted big
    std::vector<int> res = big;

    // Insert smalls in the determined order
    for (std::size_t idx = 0; idx < order.size(); ++idx)
    {
        int pair_idx = order[idx];
        if (pair_idx < (int)small.size())
            binaryInsertVector(res, small[pair_idx]);
    }

    // If there was an unpaired last element, insert it
    if (has_last) binaryInsertVector(res, last_val);

    v.swap(res);
}

void sortDeque(std::deque<int> &d)
{
    if (d.empty()) return;
    int n = (int)d.size();
    std::deque<int> big;
    std::vector<int> small; small.reserve(n/2 + 1);
    int i = 0;
    for (; i + 1 < n; i += 2)
    {
        int a = d[i];
        int b = d[i+1];
        if (a < b) { big.push_back(b); small.push_back(a); }
        else { big.push_back(a); small.push_back(b); }
    }
    bool has_last = false;
    int last_val = 0;
    if (i < n) { has_last = true; last_val = d[i]; }

    sortDeque(big);

    int m = (int)big.size();
    std::vector<int> order = insertionOrder(m);

    std::deque<int> res;
    for (std::size_t t = 0; t < big.size(); ++t) res.push_back(big[t]);

    for (std::size_t idx = 0; idx < order.size(); ++idx)
    {
        int pair_idx = order[idx];
        if (pair_idx < (int)small.size())
            binaryInsertDeque(res, small[pair_idx]);
    }

    if (has_last) binaryInsertDeque(res, last_val);

    d.swap(res);
}
