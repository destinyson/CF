/**********************************5B. Center Alignment**********************************
time limit per test:1 second
memory limit per test:64 megabytes
input:standard input
output:standard output

Almost every text editor has a built-in function of center text alignment. The developers of the popular in Berland text editor «Textpad» decided to introduce this functionality into the fourth release of the product.

You are to implement the alignment in the shortest possible time. Good luck!

Input
The input file consists of one or more lines, each of the lines contains Latin letters, digits and/or spaces. The lines cannot start or end with a space. It is guaranteed that at least one of the lines has positive length. The length of each line and the total amount of the lines do not exceed 1000.

Output
Format the given text, aligning it center. Frame the whole text with characters «*» of the minimum size. If a line cannot be aligned perfectly (for example, the line has even length, while the width of the block is uneven), you should place such lines rounding down the distance to the left or to the right edge and bringing them closer left or right alternatively (you should start with bringing left). Study the sample tests carefully to understand the output format better.

Examples
input
This  is

Codeforces
Beta
Round
5
output
************
* This  is *
*          *
*Codeforces*
*   Beta   *
*  Round   *
*     5    *
************

input
welcome to the
Codeforces
Beta
Round 5

and
good luck
output
****************
*welcome to the*
*  Codeforces  *
*     Beta     *
*   Round 5    *
*              *
*      and     *
*  good luck   *
****************
*****************************************************************************************/

// 利用vector存储文本，同时统计各行文本最大长度

// 之后按规则输出即可

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> content;
    string msg;
    bool left = false;
    int max_len = 0;
    while (getline(cin, msg))
    {
        int len = msg.length();
        content.push_back(msg);
        max_len = max_len > len ? max_len : len;
    }
    for (int i = 0; i < max_len + 2; i++)
        cout << "*";
    cout << endl;
    int num = content.size();
    for (int i = 0; i < num; i++)
    {
        cout << "*";
        int len = content[i].length();
        int differ = max_len - len;
        for (int j = 0; j < (differ >> 1); j++)
            cout << " ";
        if (differ % 2 && left)
            cout << " ";
        cout << content[i];
        for (int j = 0; j < (differ >> 1); j++)
            cout << " ";
        if (differ % 2 && (!left))
            cout << " ";
        if (differ % 2)
            left = !left;
        cout << "*" << endl;
    }
    for (int i = 0; i < max_len + 2; i++)
        cout << "*";
    cout << endl;
    return 0;
}