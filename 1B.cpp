/**************************************1B.Spreadsheets**************************************
time limit per test:10 seconds
memory limit per test:64 megabytes
input:standard input
output:standard output

In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.

Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.

Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.

Input
The first line of the input contains integer number n (1 ≤ n ≤ 105), the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .

Output
Write n lines, each line should contain a cell coordinates in the other numeration system.

Examples
input
2
R23C55
BC23
output
BC23
R23C55
********************************************************************************************/


// 首先判断转化前是何种形式，之后按题目规则转化即可

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        while (n--) {
            string pos;
            cin >> pos;
            int status = 1;
            int len = pos.length();
            bool beg = false;
            for (int i = 0; i < len; i++) {
                if (beg == false && pos[i] <= '9' && pos[i] >= '0')
                    beg = true;
                if (beg == true && pos[i] == 'C') {
                    status = 2;
                    break;
                }
            }
            switch (status) {
            case 1: {
                string srow = "";
                string scol = "";
                int col = 0;
                int flag = 0;
                while (flag < len) {
                    if (pos[flag] <= 'Z' && pos[flag] >= 'A')
                        col = col * 26 + (int)pos[flag] - 64;
                    else
                        srow.append(1, pos[flag]);
                    flag++;
                }
                while (col) {
                    scol.insert(0, 1, (char)(col % 10 + 48));
                    col = col / 10;
                }
                cout << "R" << srow << "C" << scol << endl;
                break;
            }
            case 2: {
                string srow = "";
                string scol = "";
                int col = 0;
                int flag = 1;
                while (pos[flag] != 'C') {
                    srow.append(1, pos[flag]);
                    flag++;
                }
                flag++;
                while (flag < len) {
                    col = col * 10 + (int)pos[flag] - 48;
                    flag++;
                }
                while (col) {
                    if (col % 26) {
                        scol.insert(0, 1, (char)(col % 26 + 64));
                        col = col / 26;
                    }
                    else {
                        scol.insert(0, 1, 'Z');
                        col = col / 26 - 1;
                    }
                }
                cout << scol << srow << endl;
                break;
            }
            default: break;
            }
        }
    }
    return 0;
}