struct Node {
   int value;
   Node* left;
   Node*right;

   Node(int x) {
      value = x;
      left = nullptr;
      right = nullptr;
   }

};
struct MyBST {
   Node* root;
   
   MyBST() {
      root = nullptr;
   }

   Node* insertNode(Node* root, int x) {
      if (root == nullptr) {
         return new Node(x);
      }
      if (x < root->value) {
         root->left = insertNode(root->left, x);
      } else if (x > root-> value) {
         root->right = insertNode(root->right, x);
      }

      return root;
   }

   void insert(int x) {
      root = insertNode(root, x);
   }

   Node* getMaxNode(Node* root) {
       if (root == nullptr) return nullptr;
       if (root->right == nullptr) return root;
       return getMaxNode(root->right);
   }

   int getMax() {
       Node* node = getMaxNode(root);
       
       if (node == nullptr) return -1;
       
       return node->value;
   }

   int getMin() {
       if (root == nullptr) return -1;
       
       Node* node = root;
       
       while (node->left != nullptr) {
        node = node->left;
       }
       
       return node->value;
   }
   Node* removeNode(Node* root, int x) {
      if (root == nullptr) return nullptr;
      
      if (x < root->value) {
         root->left = removeNode(root->left, x);
         return root;
      }
      
      if (x > root->value) {
         root->right = removeNode(root->right, x);
         return root;
      }
      
      if (root->left == nullptr) {
         Node* tmp = root->right;
         delete root;
         return tmp;
      }
      
      if (root->right == nullptr) {
         Node* tmp = root->left;
         delete root;
         return tmp;
      }
      
      Node* tmp = getMaxNode(root->left);
      root->value = tmp->value;
      root->left = removeNode(root->left, tmp->value);
      
      return root;
   }

   void remove(int x) {
      root = removeNode(root, x);
   }

   Node* containsNode(Node* root, int x) {
       if (root == nullptr) return nullptr;
       if (root->value == x) return root;
       if (root->value > x) return containsNode(root->left, x);
       return containsNode(root->right, x);
   }
   
   int contains(int x) {
      if (containsNode(root, x) == nullptr) return 0;
      return 1;
   }
};
