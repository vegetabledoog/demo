#include <iostream>
#include <cstdlib>
using namespace std;
// 我的版本
// int Fibonacci(int pos)
// {
//     unsigned int elem;
//     int n1 = 1, n2 = 1;
//     // 检查不合理的值，可以确定所求最大的值的位置
//     if (pos <= 0)
//     {
//         exit(-1);
//     }

//     else if (pos > 0 && pos < 3)
//     {
//         elem = 1;
//     }
//     else
//     {
//         for (int index = 3; index <= pos; index++)
//         {
//             elem = n1 + n2;
//             n1 = n2;
//             n2 = elem;
//         }
//     }
//     return elem;
// }

// 课本的优化版本
bool Fibonacci(int pos, int &elem)
{
    int n1 = 1, n2 = 1;
    // 检查不合理的值，考虑int的数据范围
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }
    // 走到这里时，pos一定在0-1024范围内
    // else if (pos > 0 && pos < 3)
    // {
    elem = 1;
    for (int index = 3; index <= pos; ++index)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}

int main()
{
    int position;
    int elem;
    while (1)
    {
        cout << "enter a position:" << endl;
        cin >> position;
        if (Fibonacci(position, elem))
        {
            cout << "element # " << position
                 << " is " << elem << endl;
        }
        else
        {
            cout << "Sorry. Could not calculate element # "
                 << position << endl;
        }
    }
}
