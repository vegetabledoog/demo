#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void display(vector<int> vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}
ofstream ofil("text_out1");
void bublle_sort(vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        for (int jx = ix + 1; jx < vec.size(); jx++)
        {
            if (vec[ix] > vec[jx])
            {
                // 调试用的输出信息
                ofil << "about to call swap!"
                     << " ix: " << ix << " jx: " << jx << '\t'
                     << "sawpping: " << vec[ix]
                     << " with " << vec[jx] << endl;

                swap(vec[ix], vec[jx]);
            }
        }
    }
}

int main()
{
    int ia[8] = {8, 33, 1, 56, 15, 98, 5, 14};
    vector<int> vec(ia, ia + 8);

    cout << "vector before sort:";
    display(vec);

    bublle_sort(vec);

    cout << "vector after sort:";
    display(vec);
}