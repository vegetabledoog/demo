#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int num_tries;
    int num_right;
    // 输入输出是针对程序来说的
    // 以输出模式打开
    // ofstream outfile("seq_data.txt");
    // 以追加模式打开,从新的一行开始
    ofstream outfile1("seq_data.txt", ios_base::app);
    // 打开失败
    cin >> name;
    cin >> num_tries >> num_right;
    if (!outfile1)
    {
        // cerr和cot的区别：cerr的输出结果并无buffer-他会立即显示于用户终端中。
        cerr << "Oops! Unable to save session data!\n";
    }
    else
    {
        // outfile打开成功，接下来将数据写入
        outfile1 << name << ' '
                 << num_tries << ' '
                 << num_right << endl;
    }
}