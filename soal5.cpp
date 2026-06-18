#include "RedBlackTree.h"
#include <iostream>
#include <string>
using namespace std;

void preorderHelper(const RedBlackTree::Node *node,
                    const RedBlackTree::Node *nil) {
  if (node == nil || node->isNil)
    return;
  cout << node->key << " ";
  preorderHelper(node->left, nil);
  preorderHelper(node->right, nil);
}

void inorderHelper(const RedBlackTree::Node *node,
                   const RedBlackTree::Node *nil) {
  if (node == nil || node->isNil)
    return;
  inorderHelper(node->left, nil);
  cout << node->key << " ";
  inorderHelper(node->right, nil);
}

void postorderHelper(const RedBlackTree::Node *node,
                     const RedBlackTree::Node *nil) {
  if (node == nil || node->isNil)
    return;
  postorderHelper(node->left, nil);
  postorderHelper(node->right, nil);
  cout << node->key << " ";
}

void preorder(const RedBlackTree &tree) {
  preorderHelper(tree.root(), tree.nil());
}

void inorder(const RedBlackTree &tree) {
  inorderHelper(tree.root(), tree.nil());
}

void postorder(const RedBlackTree &tree) {
  postorderHelper(tree.root(), tree.nil());
}


int main() {
  // Banyak nya Node
  int N;
  cin >> N;

  RedBlackTree tree;

  // Insert node
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    if (!tree.contains(val)) { 
      tree.insert(val);
    }
  }

  if (tree.empty()) {
    cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
    return 0;
  }

  // Banyaknya Langkah Travers
  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    string query;
    cin >> query;
    if (query == "PREORDER") {
      cout << "[Preorder]  : ";
      preorder(tree);
      cout << endl;
    } else if (query == "INORDER") {
      cout << "[Inorder]   : ";
      inorder(tree);
      cout << endl;
    } else if (query == "POSTORDER") {
      cout << "[Postorder] : ";
      postorder(tree);
      cout << endl;
    } else if (query == "ALL") {
      cout << "[Preorder]  : ";
      preorder(tree);
      cout << endl;
      cout << "[Inorder]   : ";
      inorder(tree);
      cout << endl;
      cout << "[Postorder] : ";
      postorder(tree);
      cout << endl;
    }
  }

  return 0;
}
