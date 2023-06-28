#include <iostream>
#include <map>
#include <vector>
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define openfile(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
using namespace std;


int n;
int main()
{
    openfile(comp);

    cin >> n;
    int keys[n];
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        keys[i] = a;
    }

    int largeL[100001]{0}, largeR[100001]{0};
    int indexedLA[n], indexedRA[n];
    for (int i = 0; i < n; i++)
    {
        largeL[keys[i]] = largeL[keys[i] - 1] + 1;
        indexedLA[i] = largeL[keys[i]];
    }
    for (int i = 0; i < n; i++)
    {
        largeR[keys[n - i - 1]] = largeR[keys[n - i - 1] - 1] + 1;
        indexedRA[i] = largeR[keys[n - i - 1]];
    }


    int best = 0;
    for (int i = 0; i < n; i++)
    {
        best = max(best, min(indexedLA[i],indexedRA[n-i-1]));
    }
    cout << n - 2*best+1;
}
