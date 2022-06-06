#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal;
const int seq_cnt = 6;
// 每个指针都指向vector<int>对象，seq_addrs是一个数组，数组元素类型为vector <int> *。
// 遍历指针
// 实现随机选择数列
int main()
{
    // 野指针
    int *bi;
    int ival = 1024;
    // 初始化null指针
    int *pi = 0;

    //验证是否为null指针
    if (!pi)
    {
        cout << "1"; // pi为null
    }
    // 指针赋值
    // 修改指针所指对象的值
    //*pi = 1024;

    return 0;
}