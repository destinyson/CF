/********************************5D. Follow Traffic Rules********************************
time limit per test:1 second
memory limit per test:64 megabytes
input:standard input
output:standard output

Everybody knows that the capital of Berland is connected to Bercouver (the Olympic capital) by a direct road. To improve the road's traffic capacity, there was placed just one traffic sign, limiting the maximum speed. Traffic signs in Berland are a bit peculiar, because they limit the speed only at that point on the road where they are placed. Right after passing the sign it is allowed to drive at any speed.

It is known that the car of an average Berland citizen has the acceleration (deceleration) speed of a km/h 2, and has maximum speed of v km/h. The road has the length of l km, and the speed sign, limiting the speed to w km/h, is placed d km (1 ≤ d < l) away from the capital of Berland. The car has a zero speed at the beginning of the journey. Find the minimum time that an average Berland citizen will need to get from the capital to Bercouver, if he drives at the optimal speed.

The car can enter Bercouver at any speed.

Input
The first line of the input file contains two integer numbers a and v (1 ≤ a, v ≤ 10000). The second line contains three integer numbers l, d and w (2 ≤ l ≤ 10000; 1 ≤ d < l; 1 ≤ w ≤ 10000).

Output
Print the answer with at least five digits after the decimal point.

Examples
input
1 1
2 1 3
output
2.500000000000

input
5 70
200 170 40
output
8.965874696353
*****************************************************************************************/

// 简单的高一物理，只是需要分各种情况进行讨论

// 主要根据为在监测点状态如何（加速还是减速还是匀速）、减速的话减速前是否为车辆最大速度

// 以及监测点后是否加速、是否要加速至车辆最大速度

// 根据不同情况计算时间

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int a, v, l, w, d;
    while (cin >> a >> v >> l >> d >> w)
    {
        double first_time;
        double test_speed;
        double second_time;
        if (v > w)
        {
            if (w * w > 2 * a * d)
            {
                first_time = sqrt(2.0 * d / (double)a);
                test_speed = sqrt(2.0 * a * d);
            }
            else
            {
                test_speed = w;
                if (2 * v * v - w * w < 2 * a * d)
                    first_time = (double)d / (double)v + (double)(v - w) / (double)a
                    + (double)(w * w) / (2.0 * a * v);
                else
                    first_time = (sqrt(4.0 * a * d + 2.0 * w * w) - w) / (double)a;
            }
        }
        else
        {
            if (v * v > 2 * a * d)
            {
                first_time = sqrt(2.0 * d / (double)a);
                test_speed = sqrt(2.0 * a * d);
            }
            else
            {
                first_time = (double)d / (double)v + (double)v / (2.0 * a);
                test_speed = v;
            }
        }
        if (test_speed == v)
            second_time = (double)(l - d) / (double)v;
        else if (v * v - test_speed * test_speed <= 2 * a * (l - d))
            second_time = (double)(l - d) / (double)v + (double)(test_speed * test_speed) / (2.0 * a * v) + (v - 2.0 * test_speed) / (2.0 * a);
        else
            second_time = (sqrt(2.0 * a * (l - d) + test_speed * test_speed) - test_speed) / (double)a;
        double ans = first_time + second_time;
        cout << setiosflags(ios::fixed) << setprecision(5) << ans << endl;
    }
    return 0;
}