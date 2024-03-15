#pragma once

#include <unordered_map>
#include <cstdlib>
#include <utility>
#include <string>
#include <list>

class LRUCache {
public:
    std::unordered_map<std::string, std::pair<std::list<std::string>::iterator, std::string>> ht;
    std::list<std::string> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }

    void moveToFirst(std::string key){
        dll.erase(ht[key].first);
        dll.push_front(key);
        ht[key].first=dll.begin();
    }

    std::pair<bool, std::string> Find(std::string key) {
        if(ht.find(key)==ht.end()) return std::make_pair(false, "");

        moveToFirst(key);
        return std::make_pair(true, ht[key].second);
    }

    void Insert(std::string key, std::string value) {
        if(ht.find(key)!=ht.end()){
            ht[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            ht[key]={dll.begin(), value};
            cap--;
        }

        if(cap<0){
            ht.erase(dll.back());
            dll.pop_back();
            cap++;
        }

    }
};