
#ifndef MAPTEMPLATE_NODE_H
#define MAPTEMPLATE_NODE_H

namespace TemplateMap {
    template<typename Key, typename Value>
    class Node {
    private:
        Key key;
        Value value;
        Node *parent;
        Node *left;
        Node *right;
    public:
        // constructors
        Node() : parent(nullptr), left(nullptr), right(nullptr) {};
        Node(Key key, Value value, Node *parent);
        // methods for tree
        Node<Key, Value> *insert(Node<Key, Value> *head, Node<Key, Value> *ptrNode, Key key, Value value);
        Node<Key, Value> *search(Node<Key, Value> *ptrNode, Key key);
        Node<Key, Value> *min(Node<Key, Value> *ptrNode);
        Node<Key, Value> *max(Node<Key, Value> *ptrNode);
    };

    template<typename Key, typename Value>
    Node<Key, Value> *Node<Key, Value>::insert(Node<Key, Value> *head, Node<Key, Value> *ptrNode, Key key, Value value) {
        if (head == nullptr)
            return new Node(key, value, head);
        else {
            if ()
        }
    }

    template<typename Key, typename Value>
    Node<Key, Value>::Node(Key key, Value value, Node *parent) {
        this->key = key;
        this->value = value;
        this->parent = parent;
        left = nullptr;
        right = nullptr;
    }

    template<typename Key, typename Value>
    Node<Key, Value> *Node<Key, Value>::search(Node<Key, Value> *ptrNode, Key key) {
        if (ptrNode == nullptr || key == ptrNode->key)
            return ptrNode;
        else if (key < ptrNode->key)
            return search(ptrNode->left, key);
        else
            return search(ptrNode->right, key);
    }

    template<typename Key, typename Value>
    Node<Key, Value> *Node<Key, Value>::min(Node<Key, Value> *ptrNode) {
        while (ptrNode->left != nullptr) {
            ptrNode = ptrNode->left;
        }
        return ptrNode;
    }

    template<typename Key, typename Value>
    Node<Key, Value> *Node<Key, Value>::max(Node<Key, Value> *ptrNode) {
        while (ptrNode->right != nullptr) {
            ptrNode = ptrNode->right;
        }
        return ptrNode;
    }
}

#endif //MAPTEMPLATE_NODE_H
