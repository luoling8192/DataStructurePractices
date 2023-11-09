#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct BT
{
    int index;
    bool read;
    BT *left;
    BT *right;

    BT(int x) : index(x), read(false), left(nullptr), right(nullptr) {}
};

vector<int> print(BT *root)
{
    queue<BT *> que;
    vector<int> ret;
    que.push(root);

    
    if (!root)
        return ret;

    while (!que.empty())
    {
        BT *node = que.front();
        que.pop();

        if (!node->left && !node->right)
        {
            ret.push_back(node->index);
            // cout << node->index << " ";
            continue;
        }

        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
    }

    return ret;
}0

int main()
{
    int n;
    BT *bt[100], *root;

    cin >> n;
    for (int i = 0; i < n; i++)
        bt[i] = new BT(i);

    for (int i = 0; i < n; i++)
    {
        char l, r;
        cin >> l >> r;

        l = l == '-' ? -1 : l - '0';
        r = r == '-' ? -1 : r - '0';

        if (l != -1)
        {
            bt[i]->left = bt[l];
            bt[l]->read = true;
        }

        if (r != -1)
        {
            bt[i]->right = bt[r];
            bt[r]->read = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!bt[i]->read)
            root = bt[i];
    }

    vector vec = print(root);
    for (int i = 0; i < vec.size(); i++)
    {
        if (i + 1 == vec.size())
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }

    //cout << endl;
    return 0;
}
