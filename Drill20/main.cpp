#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
using namespace std;

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main() {
    array<int, 10> arra = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> veca = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lisa = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> arrb = arra;
    vector<int> vecb = veca;
    list<int> lisb = lisa;
    for (int i = 0; i < 10; i++)
    {
        arra[i] += 2;
        veca[i] += 3;
    }
    for (auto x : lisa)
    {
        x = x + 5;
    }
    
    my_copy(arra.begin(), arra.end(), veca.begin());
    my_copy(lisa.begin(), lisa.end(), arra.begin());
    auto it = find(begin(veca), end(veca), 3);
    if (it != veca.end())
        cout << "Megtaláltuk a 3-ast! " << *it << endl;
    auto ot = find(lisa.begin(), lisa.end(), 27);
    if (ot != lisa.end())
        cout << "Megtaláltuk a 27-est!" << *ot << endl;
}