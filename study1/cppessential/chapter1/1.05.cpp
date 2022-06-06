#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
using namespace std;
const int seq_size = 18; // not use
const int max_seq = 6;
string seq_names[max_seq] = {
    "Fibonacci",
    "Lucas",
    "Pell",
    "Triangular",
    "Square",
    "Pentagonal"};
vector<int> pell_seq[seq_size];
int elem_vals[seq_size] =
    {
        1, 2, 3,  // Fibonacci
        3, 4, 7,  // Lucas
        2, 5, 12, // Pell
        3, 6, 10, // Triangular
        4, 9, 16, // Square
        5, 12, 22 // Pentagonal
};
// 将数组的值赋予向量
vector<int> elem_seq(elem_vals, elem_vals + seq_size);
// vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal; // 默认长度为0
vector<int> Fibonacci(elem_vals, elem_vals + 3);
vector<int> Lucas(elem_vals + 3, elem_vals + 6);
vector<int> Pell(elem_vals + 6, elem_vals + 9);
vector<int> Triangular(elem_vals + 9, elem_vals + 12);
vector<int> Square(elem_vals + 12, elem_vals + 15);
vector<int> Pentagonal(elem_vals + 15, elem_vals + seq_size);
vector<int> *current_vec = 0;
vector<int> *sqe_addrs[max_seq] = {
    &Fibonacci, &Lucas, &Pell,
    &Triangular, &Square, &Pentagonal};

int main()
{
    string user_name;        // 用户名
    int usr_guess;           // 用户猜测的值
    char user_rsp;           // 内层用户是否继续猜测
    bool next_seq = true;    // 是否显示下一组数列
    bool go_for_it = true;   // 用户是否想再猜一次
    bool got_it = false;     // 用户是否猜对
    int number_of_tries = 0; // 总的猜测数
    int num_right = 0;       // 总的用户答对的次数
    double score = 0.0;      // 正确率
    char try_again;          // 外层是否继续猜测
    const int max_tries = 3;
    int cur_tuple = 0;
    int seq_index; // 随机生成数
    /*  int list[10] = {
            0,
            12,
            23,
            25,
            85,
            25,
            13,
            485,
            78,
        };*/

    // 用户开始猜数
    while (next_seq == true)
    {
        srand(time(NULL)); // 生成一个种子赋予seq_cnt
        seq_index = rand() % max_seq;
        current_vec = sqe_addrs[seq_index];
        go_for_it = true; // 用户想继续猜测
        got_it = false;   // 用户所猜不正确
        int tries_cnt = 0;
        std::cout << "The first two elements of the sequence are: "
                  << (*current_vec)[0] << ", "
                  << (*current_vec)[1]
                  << "\nWhat is the next element?" << endl;
        while ((got_it == false) &&
               (go_for_it == true) && (++tries_cnt <= max_tries + 1))
        {
            //读取用户所猜的答案
            std::cin >> usr_guess;
            ++number_of_tries; // 总数
            if (usr_guess == (*current_vec)[2])
            {
                //答案正确
                ++num_right;
                got_it = true;
                std::cout << "Very good. Yes,"
                          << (*current_vec)[2]
                          << " is the next element in the "
                          << seq_names[seq_index] << " sequence.\n";
            }
            else
            {
                switch (tries_cnt)
                {
                case 1:
                    std::cout << "第一次错误！" << endl;
                    break;
                case 2:
                    std::cout << "第二次错误！" << endl;
                    break;
                case 3:
                    std::cout << "第三次错误！" << endl;
                    break;
                default:
                    std::cout << "错太多了，休息下吧！" << endl;
                    break;
                }
                if (tries_cnt < 4)
                {
                    std::cout << "do you want to continue?(y/n): " << endl;
                    std::cin >> user_rsp;
                    if (user_rsp == 'N' || user_rsp == 'n')
                        go_for_it = false;
                }

                /*				if (tries_cnt == 1)
                                {
                                    cout << "第一次错误";
                                }
                                else if (tries_cnt == 2)
                                {
                                    cout << "第二次错误";
                                }
                                else if (tries_cnt == 2)
                                {
                                    cout << "第三次错误";
                                }
                                else
                                {
                                    cout << "错太多了，休息下吧！";
                                }*/
            } //答案错误

            //询问用户是否愿意再尝试一次
            //读取用户的意愿
            //           std::cout << "do you want to continue?(y/n): " << endl;
            //           std::cin >> user_rsp;
            //           if (user_rsp == 'N' || user_rsp == 'n')
            //              go_for_it = false;
        } // 内层循环结束
        cur_tuple = cur_tuple + 3;
        std::cout << "Want to try another sequence? (Y/N)"
                  << " or input 'q' to quit." << endl;
        // char try_again;
        std::cin >> try_again;
        if (try_again == 'N' || try_again == 'n')
            next_seq = false;
        else if (try_again == 'q')
            break;
        /*        else
                {
                    seq_index = rand() % max_seq;
                    current_vec = sqe_addrs[seq_index];
                }
        */
    } // 外层循环结束
    return 0;
}