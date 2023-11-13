#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    if (dist <= tank)
    {
        return -1;
    }
    int numRefills = 0;
    int currentRefill = 0;
    int lastRefill = 0;
    int n = stops.size();
    int cur_tank = tank - stops[0];
    while (currentRefill < n - 1)
    {
        // lastRefill = currentRefill;
        while (currentRefill < n - 1 && stops[currentRefill + 1] - stops[currentRefill] <= cur_tank)
        {
            cur_tank = cur_tank - (stops[currentRefill+1] - stops[currentRefill]);
            currentRefill++;
        }

        if (currentRefill < n - 1)
        {
            numRefills++;
            cur_tank = tank;
        }

        if (stops[currentRefill] + cur_tank < stops[currentRefill + 1])
        {
            return -1;
        }
    }
    if (stops[currentRefill] + cur_tank >= dist)
    {
        return numRefills;
    }
    else if (stops[currentRefill] + tank >= dist)
    {
        return numRefills + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
