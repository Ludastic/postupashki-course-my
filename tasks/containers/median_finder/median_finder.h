#pragma once

#include <set>


class MedianFinder {
private:
    std::multiset<int, std::less<int> > storage_left;
    std::multiset<int, std::less<int> > storage_right;
    std::multiset<int>::iterator mid = storage_right.begin();

public:
    MedianFinder(){};

    void Insert(int val) {
        if (storage_right.size() == 0) {
            storage_right.insert(val);
            mid = storage_right.begin();
            return;
        } else {
            // if (*mid > val and storage.size()%2 == 0) {
            //     storage.insert(val);
            //     --mid;
            //     return;
            // }
            // else if(*mid <= val and storage.size()%2 != 0) {
            //     storage.insert(val);
            //     ++mid;
            //     return;
            // }
            // storage.insert(val);
            if (*mid > val) {
                storage_left.insert(val);
            }
            else {
                storage_right.insert(val);
            }
            int r_s = storage_right.size(), l_s = storage_left.size();
            bool condition = r_s - l_s > 1;
            if (condition) {
                storage_left.insert(*storage_right.begin());
                storage_right.erase(storage_right.begin());
                mid = storage_right.begin();
            }
            bool condition1 = l_s - r_s > 0;
            if (condition1) {
                storage_right.insert(*(--storage_left.end()));
                storage_left.erase(--storage_left.end());
                mid = storage_right.begin();
            }
        }
    }

    void Remove(int val) {
        if (*mid > val) {
            storage_left.erase(storage_left.find(val));
        }
        else if (*mid < val) {
            storage_right.erase(storage_right.find(val));
        }
        else {
            if (storage_left.size()!=0 and *(--storage_left.end()) == val) {
                storage_left.erase(storage_left.find(val));
            }
            else if (storage_right.size()!=0) {
                storage_right.erase(storage_right.begin());
                mid = storage_right.begin();
            }
        }
        int r_s = storage_right.size(), l_s = storage_left.size();
        bool condition = r_s - l_s > 1;
        if (condition) {
            storage_left.insert(*storage_right.begin());
            storage_right.erase(storage_right.begin());
            mid = storage_right.begin();
        }
        bool condition1 = l_s - r_s > 0;
        if (condition1) {
            storage_right.insert(*(--storage_left.end()));
            storage_left.erase(--storage_left.end());
            mid = storage_right.begin();
        }
    }

    int Find() {
        return *mid;
    }
};
