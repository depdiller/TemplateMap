
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
        // getters
        Key getKey() const { return this->key; }
        Value getValue() const { return this->value; }
        Node<Key, Value> *getParent() const { return this->parent; }
        Node<Key, Value> *getLeft() const { return this->left; }
        Node<Key, Value> *getRight() const { return this->right; }
        // methods for tree
        Node<Key, Value> *insert(Node<Key, Value> *head, Node<Key, Value> *ptrNode, Key key, Value value);
        Node<Key, Value> *search(Node<Key, Value> *ptrNode, Key key);
        Node<Key, Value> *min(Node<Key, Value> *ptrNode);
        Node<Key, Value> *max(Node<Key, Value> *ptrNode);
        void deleteNode(Node<Key, Value> *ptrNode);
    };

    template<typename Key, typename Value>
    Node<Key, Value> *Node<Key, Value>::insert(Node<Key, Value> *head, Node<Key, Value> *ptrNode, Key key, Value value) {
        // ptrNode == head at the beginning
        if (ptrNode == nullptr)
            return new Node(key, value, head);
        else {
            if (ptrNode->key < key)
                ptrNode->left = insert(ptrNode, ptrNode->left, key, value);
            else if (ptrNode->key > key)
                ptrNode->right = insert(ptrNode, ptrNode->right, key, value);
            // с этого момента не уверен
            else if (ptrNode->key == key) {
                if (head->left->key == ptrNode->key) {
                    delete ptrNode;
                    head->left = new Node(key, value, head);
                }
            }
            return head;
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

    template<typename Key, typename Value>
    void Node<Key, Value>::deleteNode(Node<Key, Value> *ptrNode) {
        if (ptrNode != nullptr) {
            deleteNode(ptrNode->left);
            deleteNode(ptrNode->right);
            delete ptrNode;
        }
    }
}

#endif //MAPTEMPLATE_NODE_H
