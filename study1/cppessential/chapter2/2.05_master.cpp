#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool Pentagonal(int pos, vector<int> &elem)
{
    // 检查不合理的值，考虑int的数据范围
    if (pos <= 0 || pos > 1024)
    {
        return false;
    }
    // 走到这里时，pos一定在0-1024范围内
    // else if (pos > 0 && pos < 3)
    // {
    int temp;
    for (int index = elem.size() + 1; index <= pos; ++index) // 若配合static可以减少内存的使用
    {
        temp = index * (3 * index - 1) / 2;
        elem.push_back(temp);
    }
    return true;
}

void display(vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

int main()
{
    int position;
    vector<int> elem;

    cout << "enter a position:" << endl;
    cin >> position;
    if (Pentagonal(position, elem))
    {
        cout << "ok "
             << endl;
        display(elem);
    }
    else
    {
        cout << "Sorry. Could not calculate element # "
             << position << endl;
    }
}
