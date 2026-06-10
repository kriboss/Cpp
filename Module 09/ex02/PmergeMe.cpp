#include "PmergeMe.hpp"
#include <algorithm>

static void mergeVector(std::vector<int> &v, int left, int mid, int right)
{
    std::vector<int> tmp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j]) tmp.push_back(v[i++]); else tmp.push_back(v[j++]);
    }
    while (i <= mid) tmp.push_back(v[i++]);
    while (j <= right) tmp.push_back(v[j++]);
    for (size_t k = 0; k < tmp.size(); ++k) v[left + k] = tmp[k];
}

static void mergeSortVector(std::vector<int> &v, int left, int right)
{
    if (left >= right) return;
    if (right - left < 16)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            int key = v[i];
            int j = i - 1;
            while (j >= left && v[j] > key) { v[j+1] = v[j]; --j; }
            v[j+1] = key;
        }
        return;
    }
    int mid = (left + right) / 2;
    mergeSortVector(v, left, mid);
    mergeSortVector(v, mid+1, right);
    mergeVector(v, left, mid, right);
}

void sortVector(std::vector<int> &v)
{
    if (v.empty()) return;
    mergeSortVector(v, 0, (int)v.size()-1);
}

static void mergeDeque(std::deque<int> &d, int left, int mid, int right)
{
    std::deque<int> tmp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (d[i] <= d[j]) tmp.push_back(d[i++]); else tmp.push_back(d[j++]);
    }
    while (i <= mid) tmp.push_back(d[i++]);
    while (j <= right) tmp.push_back(d[j++]);
    for (size_t k = 0; k < tmp.size(); ++k) d[left + k] = tmp[k];
}

static void mergeSortDeque(std::deque<int> &d, int left, int right)
{
    if (left >= right) return;
    if (right - left < 16)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            int key = d[i];
            int j = i - 1;
            while (j >= left && d[j] > key) { d[j+1] = d[j]; --j; }
            d[j+1] = key;
        }
        return;
    }
    int mid = (left + right) / 2;
    mergeSortDeque(d, left, mid);
    mergeSortDeque(d, mid+1, right);
    mergeDeque(d, left, mid, right);
}

void sortDeque(std::deque<int> &d)
{
    if (d.empty()) return;
    mergeSortDeque(d, 0, (int)d.size()-1);
}
