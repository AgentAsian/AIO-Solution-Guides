#include <iostream>
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define readfile(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
using namespace std;
using namespace std;
 
int main()
{
    readfile(cloud);
    int n, k;
    cin >> n >> k;
    long low = 0, high = -1, sum = 0, best = 1000000000;
    long dist[100000];
 
    for (int i = 0; i < n-1; i++)
    {
        long hold;
        cin >> hold;
        dist[i] = hold;
        high++;
        sum += hold;
        if (high - low >= k-1 )
        {
            best = min(best, sum);
            // cout << "     " <<sum << endl;
 
            sum -= dist[low];
            low++;
        }
        // cout << high << " " << low << " " << sum << endl;
    }
    cout << best;
}
