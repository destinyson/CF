/******************************6C. Alice, Bob and Chocolate******************************
time limit per test:2 seconds
memory limit per test:64 megabytes
input:standard input
output:standard output

Alice and Bob like games. And now they are ready to start a new game. They have placed n chocolate bars in a line. Alice starts to eat chocolate bars one by one from left to right, and Bob — from right to left. For each chocololate bar the time, needed for the player to consume it, is known (Alice and Bob eat them with equal speed). When the player consumes a chocolate bar, he immediately starts with another. It is not allowed to eat two chocolate bars at the same time, to leave the bar unfinished and to make pauses. If both players start to eat the same bar simultaneously, Bob leaves it to Alice as a true gentleman.

How many bars each of the players will consume?

Input
The first line contains one integer n (1 ≤ n ≤ 105) — the amount of bars on the table. The second line contains a sequence t 1, t 2, ..., t n (1 ≤ t i ≤ 1000), where t i is the time (in seconds) needed to consume the i-th bar (in the order from left to right).

Output
Print two numbers a and b, where a is the amount of bars consumed by Alice, and b is the amount of bars consumed by Bob.

Examples
input
5
2 9 8 2 7
output
2 3
*****************************************************************************************/

// 双指针指向首尾，向中间移动，根据遍历元素和判断并移动指针

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> bar(n);
        for (int i = 0; i < n; i++)
            cin >> bar[i];
        int i = -1;
        int j = n;
        int alice = 0;
        int bob = 0;
        while (i < j - 1)
        {
            if (alice == bob)
            {
                i++;
                j--;
                alice += bar[i];
                if (i == j)
                {
                    j++;
                    break;
                }
                else
                    bob += bar[j];
            }
            else if (alice > bob)
                bob += bar[--j];
            else
                alice += bar[++i];
        }
        cout << i + 1 << " " << n - j << endl;
    }
    return 0;
}