struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x = 0) {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
};

struct BinaryTree {
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    int getDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + max(getDepth(node->left), getDepth(node->right));
    }

    int depth() {
        return getDepth(root);
    }

};
