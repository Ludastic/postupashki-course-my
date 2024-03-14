#pragma once

#include <unordered_map>
#include <cstdlib>
#include <utility>
#include <string>

//class LRUCache {
//public:
//    LRUCache(size_t maxSize);
//
//    void Insert(const std::string& key, const std::string& value);
//
//    std::pair<bool, std::string> Find(const std::string& key);
//};

class Node {
public:
    std::string k;
    std::string val;
    Node* prev;
    Node* next;

    Node(std::string key, std::string value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;

        left = new Node("", "");
        right = new Node("", "");

        left->next = right;
        right->prev = left;
    }

    std::pair<bool, std::string> Find(std::string key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return std::make_pair(true, cache[key]->val);
        }
        return std::make_pair(false, "null");
    }

    void Insert(std::string key, std::string value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);

            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);

            delete lru;
        }
    }
private:
    int cap;
    std::unordered_map<std::string, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;

        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }
};
