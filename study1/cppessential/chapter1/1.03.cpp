#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    const int seq_size = 18;
    vector<int> pell_seq(seq_size); // 是圆括号，不是方括号
                                    /*	int elem_vals[seq_size] = {
                                            1, 2, 3,  3, 4, 7,  2, 5, 12,
                                            3, 6, 10, 4, 9, 16, 5, 12, 22
                                        }; */
    pell_seq[0] = 1;
    pell_seq[1] = 2;
    for (int index = 2; index < seq_size; index++)
    {
        pell_seq[index] = 2 * pell_seq[index - 1] + pell_seq[index - 2];
    }

    cout << "The first " << seq_size
         << "element of the Pell Series:\n\t";

    for (int index = 0; index < seq_size; index++)
    {
        cout << pell_seq[index] << ' ';
    }
    cout << '\n';

    //	vector<int> elem_seq(elem_vals, elem_vals + seq_size);
    return 0;
}