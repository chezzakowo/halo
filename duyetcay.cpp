struct Node {
    int val;
    Node* left, *right;

    Node (int x = 0) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    void preOrder(bool &first) {
        if (!first) cout << " ";

        cout << val;

        first = false;

        if (left != nullptr) left -> preOrder(first);
        if (right != nullptr) right -> preOrder(first);
    }

    void inOrder(bool &first) {
        if (left != nullptr) left -> inOrder(first);
        if (!first) cout << " ";
        
        cout << val;

        first = false;
        
        if (right != nullptr) right -> inOrder(first);
    }

    void postOrder(bool &first) {
        if (left != nullptr) left -> postOrder(first);
        if (right != nullptr) right -> postOrder(first);
        if (!first) cout << " ";
        
        cout << val;
        
        first = false;

    }
};

struct BinaryTree {
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }

    void preOrder() {
        bool first = true;
        
        if (root != nullptr) {
            root -> preOrder(first);
        }

        cout << "\n";
    }

    void inOrder() {
        bool first = true;
        
        if (root != nullptr) {
            root -> inOrder(first);
        }

        cout << "\n";
    }

    void postOrder() {
        bool first = true;
        
        if (root != nullptr) {
            root -> postOrder(first);
        }

        cout << "\n";
    }

    void traverse(int type) {
        if (type == 1) preOrder();
        if (type == 2) inOrder();
        if (type == 3) postOrder();
    }
};
