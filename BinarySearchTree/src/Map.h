#ifndef MAPTEMPLATE_MAP_H
#define MAPTEMPLATE_MAP_H

#include "BinarySearchTree.h"

namespace TemplateMap {

    template<typename Key, typename Value>
    class MapIteretor {
    private:
        Node<Key, Value> *currentNode;
    public:
        MapIteretor(Node<Key, Value> *ptrNode);
        bool operator!=(const MapIteretor<Key, Value> &it);
        bool operator==(const MapIteretor<Key, Value> &it);
        Node<Key, Value> &operator*();
        Node<Key, Value> *operator->();
        MapIteretor<Key, Value> &operator++();
        MapIteretor<Key, Value> operator++(int);
    };

    template<typename Key, typename Value>
    class Map {
    private:
        BinarySearchTree<Key, Value> tree;
        int sizeOfTree;
    public:
        friend class MapIteretor<Key, Value>;
        typedef MapIteretor<Key, Value> iterator;
        typedef MapIteretor<const Key, const Value> const_iterator;

        iterator begin();
        iterator end();

        int size() const { return size; }
        bool isEmpty() const;
        iterator insert(Key key, Value value);
        iterator search(Key key);

        Value &operator[](const Key &key);
        Value &operator[](Key &&key);
    };

    // MapIterator
    template<typename Key, typename Value>
    MapIteretor<Key, Value>::MapIteretor(Node<Key, Value> *ptrNode) {
        currentNode = ptrNode;
    }

    template<typename Key, typename Value>
    bool MapIteretor<Key, Value>::operator!=(const MapIteretor<Key, Value> &it) {
        return currentNode != it.currentNode;
    }

    template<typename Key, typename Value>
    bool MapIteretor<Key, Value>::operator==(const MapIteretor<Key, Value> &it) {
        return currentNode == it.currentNode;
    }

    template<typename Key, typename Value>
    Node<Key, Value> &MapIteretor<Key, Value>::operator*() {
        return *currentNode;
    }

    template<typename Key, typename Value>
    Node<Key, Value> *MapIteretor<Key, Value>::operator->() {
        return currentNode;
    }

    template<typename Key, typename Value>
    MapIteretor<Key, Value> &MapIteretor<Key, Value>::operator++() {
        currentNode = currentNode->next(currentNode);
        return *this;
    }

    template<typename Key, typename Value>
    MapIteretor<Key, Value> MapIteretor<Key, Value>::operator++(int) {
        Node<Key, Value> res(*this);
        currentNode = currentNode->next(currentNode);
        return res;
    }


    // Map
    template<typename Key, typename Value>
    MapIteretor<Key, Value> Map<Key, Value>::begin() {
        return iterator(tree.getRoot());
    }

    template<typename Key, typename Value>
    MapIteretor<Key, Value> Map<Key, Value>::end() {
        return iterator(nullptr);
    }

    template<typename Key, typename Value>
    bool Map<Key, Value>::isEmpty() const {
        return sizeOfTree == 0;
    }

    template<typename Key, typename Value>
    MapIteretor<Key, Value> Map<Key, Value>::insert(Key key, Value value) {
        return iterator(tree.insert(key, value));
    }

    template<typename Key, typename Value>
    MapIteretor<Key, Value> Map<Key, Value>::search(Key key) {
        return iterator(tree.search(key));
    }

    template<typename Key, typename Value>
    Value &Map<Key, Value>::operator[](const Key &key) {
        Map<Key, Value>::iterator tmp1 = tree.search(key);
        if (tmp1 == end()) {
            Value v;
            Map<Key, Value>::iterator tmp2 = insert(key, v);
            return tmp2.currentNode->getValue();
        }
        return tmp1.currentNode->getValue();
    }

    template<typename Key, typename Value>
    Value &Map<Key, Value>::operator[](Key &&key) {
        Map<Key, Value>::iterator tmp1 = tree.search(key);
        if (tmp1 == end()) {
            Value v;
            Map<Key, Value>::iterator tmp2 = insert(key, v);
            return tmp2.currentNode->getValue();
        }
        return tmp1.currentNode->getValue();
    }


}


#endif //MAPTEMPLATE_MAP_H
