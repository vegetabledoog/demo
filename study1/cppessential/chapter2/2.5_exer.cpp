#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename Type>
inline Type max(Type t1, Type t2)
{
    return t1 > t2 ? t1 : t2;
}

template <typename elemType>
inline elemType max(const vector<elemType> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

template <typename arrayType>
inline arrayType max(const arrayType *parray, int size)
{
    return *max_element(parray, parray + size);
}

int main()
{
    string sarray[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray + 6);

    int iarray[] = {121, 1212, 56, 78, 89, 34, 444};
    vector<int> ivec(iarray, iarray + 7);

    int imax = max(max(ivec), max(iarray, 7));
    string smax = max(max(svec), max(sarray, 6));

    cout << imax << smax << endl;
}
