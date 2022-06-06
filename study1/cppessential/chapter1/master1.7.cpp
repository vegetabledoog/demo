#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
    string temp;
    vector<string> vec1;
    ifstream infile("master1.7.txt");
    ofstream outfile("master1.7_1.txt");
    if (!infile && !outfile)
    {
        cerr << "Oops! Unable to open file!\n";
    }
    else
    {
        while (infile >> temp)
        {
            vec1.push_back(temp);
        }
        cout << "unsorted string:" << endl;
        for (int index = 0; index < vec1.size(); index++)
        {
            cout << vec1[index] << endl;
        }

        sort(vec1.begin(), vec1.end());
        if (!outfile)
        {
            cerr << "Oops! Unable to open file!\n";
        }
        cout << "sorted string:" << endl;
        for (int index = 0; index < vec1.size(); index++)
        {
            cout << vec1[index] << endl;
            outfile << vec1[index] << endl;
        }
    }
}