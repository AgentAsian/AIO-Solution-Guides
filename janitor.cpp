#include <iostream>
#define speed()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define readfile(name)                   \
    speed();                             \
    freopen(#name "in.txt", "r", stdin); \
    freopen(#name "out.txt", "w", stdout)
using namespace std;

int grid[10][100000]{0};
int tots[10][100000]{0};
int r, c, q;
int ans = 0;

int retval(int row, int col)
{
    if (row < r && col < c&&row>=0 && col>=0)
    {
        return grid[row][col];
    }
    return -1;
}
void replace(int x, int y, int change, int ox, int oy)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
    {
        // cout << "dundundun"<<x<<y;
        return;
    }

    bool delans = false;
    if (tots[x][y] == 4)
    {
        delans = true;
    }

    if (grid[ox][oy] > grid[x][y] && change < grid[x][y])
    {
        // cout << "what the pooo1";
        tots[x][y]++;
        tots[ox][oy]--;
    }
    if (grid[ox][oy] < grid[x][y] && change > grid[x][y])
    {
        // cout << "what the pooo2";

        tots[x][y]--;
        tots[ox][oy]++;
    }
    if (tots[x][y] != 4 && delans)
    {
        ans--;
    }
    if (!delans && tots[x][y] == 4) {
        ans++;
    }
}
void debug()
{
    cout << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            cout << tots[i][j] << " ";
            // retval(i,j);
        }
        cout << endl;
    }
}
int main()
{
    readfile(janitor);

    cin >> r >> c >> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            tots[i][j] = 0;
        }
    }
    // cout << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            if (retval(i + 1, j) < grid[i][j])
            {
                tots[i][j]++;
            }
            if (retval(i - 1, j) < grid[i][j])
            {
                tots[i][j]++;
            }
            if (retval(i, j + 1) < grid[i][j])
            {
                tots[i][j]++;
            }
            if (retval(i, j - 1) < grid[i][j])
            {
                tots[i][j]++;
            }
            if (tots[i][j] == 4)
            {
                ans++;
            }
            // cout << retval(i,j)  <<" ";
            // cout << tots[i][j] << " ";
            // retval(i,j);
        }
        // cout << endl;
    }
    cout << ans << endl;
    for (int i = 0; i < q; i++)
    {
        int x, y, change;
        cin >> x >> y >> change;
        x--;
        y--;
        bool delans = false;
        if (tots[x][y] == 4) {
            delans = true;
        }
        // cout << "test 1";
        replace(x + 1, y, change, x, y);
        replace(x - 1, y, change, x, y);
        replace(x, y + 1, change, x, y);
        replace(x, y - 1, change, x, y);
        // debug();
        // cout << "test 2";
        if (tots[x][y] != 4 && delans)
        {
            ans--;
        }
        if (!delans && tots[x][y] ==4) {
            ans++;
        }
        // cout << "test 2";

        grid[x][y] = change;
        cout << ans <<endl;
    }
}
