#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int N, M, a[11], b[11], la[11], lb[11], ra[11], rb[11];
    char ca[11], cb[11];

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));

    ca[0] = 1;
    cb[0] = 1;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char l, r;
        cin >> ca[i] >> l >> r;
        ca[i] -= 'A' - 1;

        la[i] = l == '-' ? -1 : l - '0';
        ra[i] = r == '-' ? -1 : r - '0';
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        char l, r;
        cin >> cb[i] >> l >> r;
        cb[i] -= 'A' - 1;
        
        lb[i] = l == '-' ? -1 : l - '0';
        rb[i] = r == '-' ? -1 : r - '0';
    }

    for (int i = 1; i <= N; i++)
    {
        int father = ca[i];
        a[father] = ca[la[i]+1] * ca[ra[i]+1];
    }

    for (int i = 1; i <= M; i++)
    {
        int father = cb[i];
        b[father] = cb[lb[i]+1] * cb[rb[i]+1];

        if (a[father] != b[father])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
