// //#pragma once
// //
// //#include <set>
// //#include <cmath>
// //#include <vector>
// //#include <unordered_set>
// //
// //class MedianFinder {
// //public:
// //    MedianFinder() = default;
// //
// //    void Insert(int val);
// //
// //    void Remove(int val);
// //
// //    int Find();
// //};
// //
// //#include <iostream>
// //#include <stdexcept>
// //
// //class Node {
// //public:
// //    int value;
// //    Node *left = nullptr;
// //    Node *right = nullptr;
// //
// //    explicit Node(int val) : value(val) {}
// //
// //    Node *getLeftest() {
// //        Node *current = this;
// //        while (current->left != nullptr) {
// //            current = current->left;
// //        }
// //        return current;
// //    }
// //
// //    Node *getRightest() {
// //        Node *current = this;
// //        while (current->right != nullptr) {
// //            current = current->right;
// //        }
// //        return current;
// //    }
// //
// //    Node *getRightestParent() {
// //        Node *current = this;
// //        while (current->right != nullptr && current->right->right != nullptr) {
// //            current = current->right;
// //        }
// //        if (current->right == nullptr) {
// //            return nullptr;
// //        }
// //        return current;
// //    }
// //
// //    Node *getLeftestParent() {
// //        Node *current = this;
// //        while (current->left != nullptr && current->left->left != nullptr) {
// //            current = current->left;
// //        }
// //        if (current->left == nullptr) {
// //            return nullptr;
// //        }
// //        return current;
// //    }
// //};
// //
// //class BinaryTree {
// //private:
// //    Node *root = nullptr;
// //    Node *leftPointer = nullptr;
// //    Node *rightPointer = nullptr;
// //    int treeSize = 0;
// //
// //public:
// //    int getMin() const {
// //        return leftPointer ? leftPointer->value : 0;
// //    }
// //
// //    int getMax() const {
// //        return rightPointer ? rightPointer->value : 0;
// //    }
// //
// //    int getSize() const {
// //        return treeSize;
// //    }
// //
// //    void insert(int value) {
// //        Node *node = new Node(value);
// //        if (root == nullptr) {
// //            root = node;
// //            leftPointer = root;
// //            rightPointer = root;
// //            treeSize += 1;
// //            return;
// //        }
// //        Node *currentNode = root;
// //        while (currentNode != nullptr) {
// //            if (value > currentNode->value) {
// //                if (currentNode->right != nullptr) {
// //                    currentNode = currentNode->right;
// //                } else {
// //                    if (currentNode == rightPointer) {
// //                        rightPointer = node;
// //                    }
// //                    currentNode->right = node;
// //                    treeSize += 1;
// //                    return;
// //                }
// //            } else {
// //                if (currentNode->left != nullptr) {
// //                    currentNode = currentNode->left;
// //                } else {
// //                    if (currentNode == leftPointer) {
// //                        leftPointer = node;
// //                    }
// //                    currentNode->left = node;
// //                    treeSize += 1;
// //                    return;
// //                }
// //            }
// //        }
// //        throw std::runtime_error("Unexpected error during insertion");
// //    }
// //
// //    bool remove(Node *&root, int value, Node *&leftPointer, Node *&rightPointer) {
// //        if (root == nullptr) {
// //            // Value not found
// //            return false;
// //        }
// //
// //        if (value < root->value) {
// //            return remove(root->left, value, leftPointer, rightPointer);
// //        } else if (value > root->value) {
// //            return remove(root->right, value, leftPointer, rightPointer);
// //        } else {
// //            if (root->left == nullptr) {
// //                Node *temp = root->right;
// //                if (root == leftPointer) {
// //                    leftPointer = (temp != nullptr) ? temp->getLeftest() : nullptr;
// //                }
// //                if (root == rightPointer) {
// //                    rightPointer = (rightPointer == leftPointer) ? nullptr : rightPointer;
// //                }
// //                delete root;
// //                root = temp;
// //            } else if (root->right == nullptr) {
// //                Node *temp = root->left;
// //                if (root == rightPointer) {
// //                    rightPointer = (temp != nullptr) ? temp->getRightest() : nullptr;
// //                }
// //                if (root == leftPointer) {
// //                    leftPointer = (leftPointer == rightPointer) ? nullptr : leftPointer;
// //                }
// //                delete root;
// //                root = temp;
// //            } else {
// //                Node *temp = root->right->getLeftest();
// //                root->value = temp->value;
// //                remove(root->right, temp->value, leftPointer, rightPointer);
// //            }
// //            return true;
// //        }
// //    }
// //
// //    bool remove(int value) {
// //        return remove(root, value, leftPointer, rightPointer);
// //    }
// //
// //
// //};
// // Binary Search Tree operations in C++
//
// //#include <iostream>
// //using namespace std;
// //
// //struct node {
// //    int key;
// //    struct node *left, *right;
// //    // Create a node
// //    struct node *newNode(int item) {
// //        struct node *temp = (struct node *)malloc(sizeof(struct node));
// //        temp->key = item;
// //        temp->left = temp->right = NULL;
// //        return temp;
// //    }
// //
// //// Inorder Traversal
// //    void inorder(struct node *root) {
// //        if (root != NULL) {
// //            // Traverse left
// //            inorder(root->left);
// //
// //            // Traverse root
// //            cout << root->key << " -> ";
// //
// //            // Traverse right
// //            inorder(root->right);
// //        }
// //    }
// //
// //// Insert a node
// //    struct node *insert(struct node *node, int key) {
// //        // Return a new node if the tree is empty
// //        if (node == NULL) return newNode(key);
// //
// //        // Traverse to the right place and insert the node
// //        if (key < node->key)
// //            node->left = insert(node->left, key);
// //        else
// //            node->right = insert(node->right, key);
// //
// //        return node;
// //    }
// //
// //// Find the inorder successor
// //    struct node *minValueNode(struct node *node) {
// //        struct node *current = node;
// //
// //        // Find the leftmost leaf
// //        while (current && current->left != NULL)
// //            current = current->left;
// //
// //        return current;
// //    }
// //
// //// Deleting a node
// //    struct node *deleteNode(struct node *root, int key) {
// //        // Return if the tree is empty
// //        if (root == NULL) return root;
// //
// //        // Find the node to be deleted
// //        if (key < root->key)
// //            root->left = deleteNode(root->left, key);
// //        else if (key > root->key)
// //            root->right = deleteNode(root->right, key);
// //        else {
// //            // If the node is with only one child or no child
// //            if (root->left == NULL) {
// //                struct node *temp = root->right;
// //                delete root;
// //                return temp;
// //            } else if (root->right == NULL) {
// //                struct node *temp = root->left;
// //                delete root;
// //                return temp;
// //            }
// //
// //            // If the node has two children
// //            struct node *temp = minValueNode(root->right);
// //
// //            // Place the inorder successor in position of the node to be deleted
// //            root->key = temp->key;
// //
// //            // Delete the inorder successor
// //            root->right = deleteNode(root->right, temp->key);
// //        }
// //        return root;
// //    }
// //};
// //
// //
// //class BinaryTree {
// //    node* root;
// //    int size=0;
// //    BinaryTree() = default;
// //    void insert(int value) {
// //        root->insert(root, value);
// //        size++;
// //    }
// //    bool remove(int value) {
// //        root = root->deleteNode(root, value);
// //
// //        size--;
// //        return true;
// //    }
// //
// //    int getSize() {
// //        return size;
// //    }
// //
// //    int getMax() {
// //        node* cp = root;
// //        if (cp== nullptr) {
// //            return 0;
// //        }
// //        while (cp->right!= nullptr) {
// //            cp = cp->right;
// //        }
// //
// //    }
// //};
// //
// //
// //class MedianFinder {
// //private:
// //    BinaryTree leftTree;
// //    BinaryTree rightTree;
// //public:
// //    void Insert(int value) {
// //        if (rightTree.getSize() == 0) {
// //            rightTree.insert(value);
// //            return;
// //        }
// //        int rightMinValue = rightTree.getMin();
// //        if (value > rightMinValue) {
// //            rightTree.insert(value);
// //        } else {
// //            leftTree.insert(value);
// //        }
// //        balanceTrees();
// //    }
// //
// //    bool Remove(int value) {
// //        bool deleted = false;
// //        if (value >= leftTree.getMin() and value <= leftTree.getMax()) {
// //            deleted = leftTree.remove(value);
// //        }
// //        if (!deleted and (value >= rightTree.getMin() and value <= rightTree.getMax())) {
// //            deleted = rightTree.remove(value);
// //        }
// //        if (deleted) {
// //            balanceTrees();
// //        }
// //        return deleted;
// //    }
// //
// //    int Find() {
// //        return rightTree.getMin();
// //    }
// //
// //private:
// //    void balanceTrees() {
// //        int leftSize = leftTree.getSize();
// //        int rightSize = rightTree.getSize();
// //        int diff = rightSize - leftSize;
// //        if (diff < 0) {
// //            for (int i = 0; i < abs(diff); i++) {
// //                int leftMaxValue = leftTree.getMax();
// //                leftTree.remove(leftMaxValue);
// //                rightTree.insert(leftMaxValue);
// //            }
// //        }
// //        else if(diff > 1) {
// //            for (int i = 0; i < diff-1; i++) {
// //                int rightMinValue = rightTree.getMin();
// //                leftTree.insert(rightMinValue);
// //                rightTree.remove(rightMinValue);
// //            }
// //        }
// //    }
// //
// //
// //};
//
// #include <iostream>
// using namespace std;
//
//
// class BinaryTree {
//
//     struct node {
//         int key;
//         struct node *left, *right;
//         // Create a node
//         struct node *newNode(int item) {
//             struct node *temp = new node();
//             temp->key = item;
//             temp->left = temp->right = NULL;
//             return temp;
//         }
//
// // Inorder Traversal
//         void inorder(struct node *root) {
//             if (root != NULL) {
//                 // Traverse left
//                 inorder(root->left);
//
//                 // Traverse root
//                 cout << root->key << " -> ";
//
//                 // Traverse right
//                 inorder(root->right);
//             }
//         }
//
// // Insert a node
//         struct node *insert(struct node *node, int key, bool left, bool right, BinaryTree* tree) {
//             // Return a new node if the tree is empty
//             if (node == NULL) {
//                 if (left && !right) {
//                     tree->setMin(key);
//                 } else if (right && !left) {
//                     tree->setMax(key);
//                 }
//                 return newNode(key);
//             }
//
//             // Traverse to the right place and insert the node
//             if (key < node->key)
//                 node->left = insert(node->left, key, true, right, tree);
//             else
//                 node->right = insert(node->right, key, left, true, tree);
//
//             return node;
//         }
//
// // Find the inorder successor
//         struct node *minValueNode(struct node *node) {
//             struct node *current = node;
//
//             // Find the leftmost leaf
//             while (current && current->left != NULL)
//                 current = current->left;
//
//             return current;
//         }
//
// // Deleting a node
//         struct node *deleteNode(struct node *root, int key, BinaryTree* tree, bool left, bool right) {
//             // Return if the tree is empty
//             if (root == NULL) return root;
//
//             // Find the node to be deleted
//             if (key < root->key) {
//                 root->left = deleteNode(root->left, key, tree, true, right);
//                 if (left && !right && root->left == nullptr) {
//                     tree->setMin(root->key);
//                 }
//             }
//             else if (key > root->key) {
//                 root->right = deleteNode(root->right, key, tree, left, right);
//                 if (right && !left && root->right != nullptr) {
//                     tree->setMax(root->key);
//                 }
//             }
//             else {
//                 // If the node is with only one child or no child
//                 if (root->left == NULL) {
//                     struct node *temp = root->right;
//                     delete root;
//                     if (left && !right && temp != nullptr) {
//                         tree->setMin(temp->key);
//                     }
//                     return temp;
//                 } else if (root->right == NULL) {
//                     struct node *temp = root->left;
//                     delete root;
//                     if (right && !left && root->left != nullptr) {
//                         tree->setMax(temp->key);
//                     }
//                     return temp;
//                 }
//
//                 // If the node has two children
//                 struct node *temp = minValueNode(root->right);
//
//                 // Place the inorder successor in position of the node to be deleted
//                 root->key = temp->key;
//
//                 // Delete the inorder successor
//                 root->right = deleteNode(root->right, temp->key, nullptr, false, false);
//             }
//             return root;
//         }
//     };
//     node* root;
//     int size=0;
//     int max = 0;
//     int min = 0;
//
//     void setMax(int value) {
//         max=  value;
//     }
//
//     void setMin(int value) {
//         min = value;
//     }
//
// public:
//     void insert(int value) {
//         root = root->insert(root, value, false, false, this);
//         size++;
//     }
//     bool remove(int value) {
//         root = root->deleteNode(root, value, this, false, false);
//         size--;
//         return true;
//     }
//
//     int getSize() {
//         return size;
//     }
//
//     int getMax() {
//         return max;
//     }
//
//     int getMin() {
//         return min;
//     }
// };
//
//
// class MedianFinder {
// private:
//     BinaryTree leftTree;
//     BinaryTree rightTree;
// public:
//     void Insert(int value) {
//         if (rightTree.getSize() == 0) {
//             rightTree.insert(value);
//             return;
//         }
//         int rightMinValue = rightTree.getMin();
//         if (value > rightMinValue) {
//             rightTree.insert(value);
//         } else {
//             leftTree.insert(value);
//         }
//         balanceTrees();
//     }
//
//
//     bool Remove(int value) {
//         bool deleted = false;
//         if (value >= leftTree.getMin() and value <= leftTree.getMax()) {
//             deleted = leftTree.remove(value);
//         }
//         if (!deleted and (value >= rightTree.getMin() and value <= rightTree.getMax())) {
//             deleted = rightTree.remove(value);
//         }
//         if (deleted) {
//             balanceTrees();
//         }
//         return deleted;
//     }
//
//     int Find() {
//         return rightTree.getMin();
//     }
//
// private:
//     void balanceTrees() {
//         int leftSize = leftTree.getSize();
//         int rightSize = rightTree.getSize();
//         int diff = rightSize - leftSize;
//         if (diff < 0) {
//             for (int i = 0; i < abs(diff); i++) {
//                 int leftMaxValue = leftTree.getMax();
//                 leftTree.remove(leftMaxValue);
//                 rightTree.insert(leftMaxValue);
//             }
//         }
//         else if(diff > 1) {
//             for (int i = 0; i < diff-1; i++) {
//                 int rightMinValue = rightTree.getMin();
//                 leftTree.insert(rightMinValue);
//                 rightTree.remove(rightMinValue);
//             }
//         }
//     }
//
//
// };

#pragma once

#include <set>
#include <cmath>
#include <vector>
#include <unordered_set>


class MedianFinder {
private:
    std::multiset<int> storage;
    std::multiset<int>::iterator mid;
public:
    MedianFinder() {
        mid = storage.begin();
    }

    void Insert(int val) {
        if (storage.size() == 0) {
            storage.insert(val);
            return;
        }
        else {
            if (*mid > val and storage.size()%2 == 0) {
                storage.insert(val);
                --mid;
                return;
            }
            else if(*mid <= val and storage.size()%2 != 0){
                storage.insert(val);
                ++mid;
                return;
            }
            storage.insert(val);
        }
    }

    void Remove(int val) {
        // if (*mid > val and storage.size()%2!=0) { //smaller than mid
        //     ++mid;
        //     storage.erase(storage.find(val));
        //     return;
        // }
        // else if (*mid > val and storage.size()%2 == 0) {
        //     storage.erase(storage.find(val));
        //     return;
        // }
        // else if (*mid < val and storage.size()%2!=0) { //smaller than mid
        //     --mid;
        //     storage.erase(storage.find(val));
        //     return;
        // }
        // else if (*mid < val and storage.size()%2!=0) {
        //     storage.erase(storage.find(val));
        //     return;
        // }
        // else if (*mid == val and mid == storage.find(val)) { //val == mid, mid - lefttest
        //     if (storage.size() % 2 == 0) {
        //         --mid;
        //         storage.erase(storage.find(val));
        //
        //         return;
        //     }
        //     else {
        //         ++mid;
        //         storage.erase(storage.find(val));
        //         return;
        //     }
        // }
        // else if(*mid == val and mid!=storage.find(val)){ //val == mid, mid - not leftest, deleting in the left part
        //     if (storage.size() % 2 != 0) {
        //         ++mid;
        //         storage.erase(storage.find(val));
        //         return;
        //     }
        //     else {
        //         storage.erase(storage.find(val));
        //         return;
        //     }
        // }
        // storage.erase(storage.find(val));
        // return;
            if (*mid > val and storage.size()%2 != 0) {
                ++mid;
                storage.erase(storage.erase(val));
                return;
            }
            else if(*mid <= val and storage.size()%2 == 0){
                --mid;
                storage.erase(storage.find(val));
                return;
            }
            storage.erase(storage.find(val));
    }

    int Find() {
        return *mid;
    }
};

