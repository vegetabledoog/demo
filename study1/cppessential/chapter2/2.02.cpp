#include <iostream>
#include <cstdlib>
using namespace std;
bool print_sequence(int pos)
{
    int n1 = 1, n2 = 1;
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos
             << " -- cannot handle request!\n";

        return false;
    }
    cout << "The Fibonacci Sequence for "
         << pos << " positions: \n\t";

    // 所有位置都会打印出1，只有 pos==1 除外
    switch (pos)
    {
    default:
    case 2:
        cout << "1 ";
        // 注意,此处没有break;
    case 1:
        cout << "1 ";
        break;
    }
    int elem;
    for (int index = 3; index <= pos; ++index)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
        // 每输出10个元素就换行
        cout << elem << (!(index % 10) ? "\n\t" : " ");
    }
    cout << endl;
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
        if (print_sequence(position))
        {
            cout << "element #" << position
                 << " is " << elem << endl;
        }
        else
        {
            cout << "Sorry. Could not calculate element # "
                 << position << endl;
        }
        cout << "if you want quit,enter 'q', enter anything else to continue." << endl;
        char a;
        cin >> a;
        if (a == 'q')
            break;
    }
    return 0;
}
