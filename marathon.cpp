/*
    marathon of D distance 
    5 different paces, time consumed per km and its energy consumption.
    he had energy left.
    Find the minimum time required for choi to complete marathon if he has E energy.
*/
#include <iostream>
using namespace std;
struct profile
{
    int time;
    int energy;
};
profile p[5];
int ans;
void func(int i, int E, int D, int sum)
{
    //if current answer is greater than previously found smaller answer
    if (sum > ans || E < 0)
        return;
    //if we have reached the distance
    if (D <= 0)
    {
        ans = min(sum, ans);
        return;
    }
    //if all the profiles are covered for given recursion
    if (i >= 5)
        return;
    //same pace profile for next one km
    func(i, E - (p[i].energy), D - 1, sum + (p[i].time));
    //next pace profile
    func(i + 1, E, D, sum);
}
void solve()
{
    int energy, distance;
    cin >> energy >> distance;
    profile p[5];
    for (int i = 0; i < 5; i++)
    {
        int min, sec;
        //time consumed per km
        cin >> min >> sec;
        //energy consumed
        cin >> p[i].energy;
        p[i].time = 60 * min + sec;
    }
    ans = 99999999;
    //for first profile, distance, total energy, current answer
    func(0, energy, distance, 0);
    cout << ans / 60 << " " << ans % 60 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
