#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "hmh";
    int num_tries = 7;
    int num_right = 2;
    // 读
    /*   ifstream infile("seq_data.txt", ios_base::app);
       // 打开失败
       if (!infile)
       {
           cerr << "Oops! Unable to open file!\n";
       }
       else
       {
           // 以文件中的空格为分隔符
           infile >> name >> num_tries >> num_right;
           cout << "name:" << name << endl
                << "num_tries:" << num_tries << endl
                << "num_right:" << num_right << endl;
       }
   */
    // 同时读写
    fstream file("seq_data.txt", ios_base::in | ios_base::app);
    // 以追加模式打开文件时，指针在文件末尾
    if (!file)
    {
        cerr << "Oops! Unable to open file!\n";
    }
    else
    {
        // 写
        file << name << ' '
             << num_tries << ' '
             << num_right << endl;

        // 由于app，开始读前，将文件指针重定位到起始处
        file.seekg(0);
        file >> name >> num_tries >> num_right;
        cout << name << endl
             << num_tries << endl
             << num_right << endl;
    }
}