#ifndef MAPTEMPLATE_BINARYSEARCHTREE_H
#define MAPTEMPLATE_BINARYSEARCHTREE_H

#include "Node.h"

namespace TemplateMap {

    template<typename Key, typename Value>
    class BinarySearchTree {
    private:
        Node<Key, Value> *root;
    public:
        // constructors
        BinarySearchTree() : root(nullptr) {};
        // destructor
        ~BinarySearchTree();
        // methods
        BinarySearchTree<Key, Value> &insert(Key key, Value value);
        Node<Key, Value> *search(Key key);
        Node<Key, Value> *min();
        Node<Key, Value> *max();
        Value &getValueByKey(Key key) const;
    };

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::min() {
        return root->min(root);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::max() {
        return root->max(root);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *BinarySearchTree<Key, Value>::search(Key key) {
        return root->search(root, key);
    }

    template<typename Key, typename Value>
    BinarySearchTree<Key, Value> &BinarySearchTree<Key, Value>::insert(Key key, Value value) {
        root->insert(root, root, key, value);
        return *this;
    }

    template<typename Key, typename Value>
    BinarySearchTree<Key, Value>::~BinarySearchTree() {
        root->deleteNode(root);
    }

    template<typename Key, typename Value>
    Value &BinarySearchTree<Key, Value>::getValueByKey(Key key) const {
        return root->search(root,key)->getValue();
    }
}


#endif //MAPTEMPLATE_BINARYSEARCHTREE_H