#include <iostream>

using namespace std;

struct AVL {
    int value;
    int height;
    AVL *left;
    AVL *right;

    explicit AVL(int x) : value(x), height(1), left(nullptr), right(nullptr) {}

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int getHeight(AVL *root) {
        if (!root)
            return 0;
        return root->height;
    }

    static AVL *insert(AVL *root, int value) {
        if (!root)
            return new AVL(value);

        if (value < root->value) {
            root->left = insert(root->left, value);
            if (getHeight(root->left) - getHeight(root->right) == 2) {
                if (value < root->left->value) {
                    root = rotateLeft(root);
                } else {
                    root = rotateLR(root);
                }
            }
        }

        if (value > root->value) {
            root->right = insert(root->right, value);
            if (getHeight(root->left) - getHeight(root->right) == -2) {
                if (value > root->right->value) {
                    root = rotateRight(root);
                } else {
                    root = rotateRL(root);
                }
            }
        }

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        return root;
    }

    static AVL *rotateLeft(AVL *root) {
        AVL *new_root = root->left;
        root->left = new_root->right;
        new_root->right = root;

        // Update Tree Height
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        new_root->height = max(getHeight(new_root->left), root->height) + 1;

        return new_root;
    }

    static AVL *rotateRight(AVL *root) {
        AVL *new_root = root->right;
        root->right = new_root->left;
        new_root->left = root;

        // Update Tree Height
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        new_root->height = max(getHeight(new_root->right), root->height) + 1;

        return new_root;
    }

    static AVL *rotateLR(AVL *root) {
        root->left = rotateRight(root->left); // LRL
        return rotateLeft(root); // L
    }

    static AVL *rotateRL(AVL *root) {
        root->right = rotateLeft(root->right); // RLR
        return rotateRight(root); // R
    }
};


int main() {
    int n;
    cin >> n;

    AVL *root = nullptr;
    while (n--) {
        int x;
        cin >> x;
        root = AVL::insert(root, x);
    }

    cout << root->value;
    return 0;
}
