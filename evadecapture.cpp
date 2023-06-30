#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define readfile(name)                   \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
using namespace std;
int n, e, x, k;

vector<vector<int>> adj;
set<int> places;
set<pair<int, int>> mem;
bool visite[100000];
bool visito[100000];

int main()
{

    readfile(evading);
    cin >> n >> e >> x >> k;
    for (int i = 0; i < n; i++)
    {
        adj.push_back({});
    }
    // cout << "yo";

    for (int i = 0; i < e; i++)
    {
        int s, a;
        cin >> s >> a;
        s--;
        a--;
        adj[s].push_back(a);
        adj[a].push_back(s);
    }

    queue<int> possible;
    int steps = k;
    possible.push(x - 1);

    while (possible.size() != 0 && steps >= 0)
    {
        int size = possible.size();
        for (int i = 0; i < size; i++)
        {
            int hold = possible.front();
            possible.pop();
            int l = hold;

            if (steps % 2 == 0)
            {
                visite[l] = true;
                places.insert(l);
            }
            else
            {
                visito[l] = true;
            }

            for (int i = 0; i < adj[l].size(); i++)
            {
                if ((steps - 1) % 2 == 1 && !visito[adj[l][i]])
                {
                    visito[adj[l][i]] = true;

                    possible.push(adj[l][i]);
                }
                if ((steps - 1) % 2 == 0 && !visite[adj[l][i]])
                {
                    visite[adj[l][i]] = true;
                    possible.push(adj[l][i]);
                }
            }
        }
        steps--;
    }
    cout << places.size();

    // for (auto it = places.begin(); it != places.end(); ++it)
    //     cout << ' ' << *it + 1;
}
