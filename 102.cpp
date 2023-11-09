#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, arr[10000];
    scanf("%d", &n);

    int max = -1, curr = 0, l = 0, r = 0, a = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[i] = x;

        curr += x;

        if (curr > max)
        {
            max = curr;
            l = a;
            r = i;
        }
        else if (curr < 0)
        {
            curr = 0;
            a = i + 1;
        }
    }

    if (max < 0)
        printf("%d %d %d\n", 0, arr[l], arr[n-1]);
    else
        printf("%d %d %d\n", max, arr[l], arr[r]);
    return 0;
}
