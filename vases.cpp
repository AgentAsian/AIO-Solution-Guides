#include <iostream>
#define speed() \
ios::sync_with_stdio(false); \
cin.tie(0)
#define readfile(name) \
speed(); \
freopen(#name "in.txt","r",stdin); \
freopen(#name "out.txt","w",stdout)
using namespace std;

int main() {
    readfile(vases);
    int n;
    cin >> n;
    if (n<6) {
        cout << "0 0 0";
    }
    else {
        cout <<"1 2 " << n-3;
    }
}
