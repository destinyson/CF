/***********************************4B. Before an Exam***********************************
time limit per test:0.5 second
memory limit per test:64 megabytes
input:standard input
output:standard output

Tomorrow Peter has a Biology exam. He does not like this subject much, but d days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than minTime i and not more than maxTime i hours per each i-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions.

So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours sumTime spent him on preparation, and now he wants to know if he can show his parents a timetable sсhedule with d numbers, where each number sсhedule i stands for the time in hours spent by Peter each i-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all schedule i should equal to sumTime.

Input
The first input line contains two integer numbers d, sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following d lines contains two integer numbers minTime i, maxTime i (0 ≤ minTime i ≤ maxTime i ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.

Output
In the first line print YES, and in the second line print d numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.

Examples
input
1 48
5 7
output
NO

input
2 5
0 1
3 5
output
YES
1 4
*****************************************************************************************/

// 求一下最小总时间和最大总时间，如果所给总时间不在这个范围内，那是不可能给出时间表的

// 如果在这个范围内，那么进行逐天调整，从第一天开始增加复习时间直到第一天的最大值，第二天同理

// 依此类推，直到总时间达到所给总时间即可

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int d, sumTime;
    cin >> d >> sumTime;
    vector<int> ansTime(d);
    vector<int> maxTime(d);
    int minsum = 0;
    int maxsum = 0;
    for (int i = 0; i < d; i++)
    {
        cin >> ansTime[i] >> maxTime[i];
        minsum += ansTime[i];
        maxsum += maxTime[i];
    }
    if (sumTime < minsum || sumTime > maxsum)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int D_value = sumTime - minsum;
        for (int i = 0; i < d; i++)
        {
            if (D_value)
            {
                if (ansTime[i] + D_value <= maxTime[i])
                {
                    ansTime[i] += D_value;
                    D_value = 0;
                }
                else
                {
                    D_value -= (maxTime[i] - ansTime[i]);
                    ansTime[i] = maxTime[i];
                }
            }
            cout << ansTime[i];
            if (i == d - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}