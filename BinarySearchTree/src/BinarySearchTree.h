#ifndef MAPTEMPLATE_BINARYSEARCHTREE_H
#define MAPTEMPLATE_BINARYSEARCHTREE_H

#include "Node.h"

namespace TemplateMap {

    template<typename Key, typename Value>
    class BinarySearchTree {
    private:
        Node<Key, Value> *root;
        Node<Key, Value> *clone(Node<Key, Value> *node);
    public:
        // constructors
        BinarySearchTree() : root(nullptr) {};
        // destructor
        ~BinarySearchTree();
        // methods
        Node<Key, Value> *insert(Key key, Value value);
        Node<Key, Value> *search(Key key) const;
        Node<Key, Value> *min() const;
        Node<Key, Value> *max() const;
//        Node<Key, Value> *next(const Key &);
        Value &getValueByKey(Key key) const;
        Node<Key, Value> *getRoot() const { return root; }

        BinarySearchTree<Key, Value> &operator=(const BinarySearchTree &other);
    };
//    template<typename Key, typename Value>
//    Node<Key, Value> *BinarySearchTree<Key, Value>::next(const Key &key) {
//        Node<Key, Value> *tmp = search(key);
//        return tmp->next(tmp);
//    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::min() const {
        return root->min(root);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::max() const {
        return root->max(root);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::search(Key key) const {
        return root->search(root, key);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::insert(Key key, Value value) {
        root = root->insert(root, key, value);
        return root->search(root, key);
    }

    template<typename Key, typename Value>
    BinarySearchTree<Key, Value>::~BinarySearchTree() {
        root->deleteNodeRecursion(root);
    }

    template<typename Key, typename Value>
    Value &BinarySearchTree<Key, Value>::getValueByKey(Key key) const {
        return root->search(root,key)->getValue();
    }

    template<typename Key, typename Value>
    BinarySearchTree<Key, Value> &BinarySearchTree<Key, Value>::operator=(const BinarySearchTree &other) {
        if (this != &other) {
            if (this != nullptr)
                root->deleteNodeRecursion(root);
            this->root = new BinarySearchTree();
            this->root = other->clone(other->root);
            // Returns a new binary tree
            return *this;
        }
        else
            return *this;
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::clone(Node<Key, Value> *node) {
        if (node != nullptr) {
            Node<Key, Value> *point = new Node(node->data);
            point->left = this->clone(node->left);
            point->right = this->clone(node->right);
            return point;
        }
        return nullptr;
    }
}


#endif //MAPTEMPLATE_BINARYSEARCHTREE_H