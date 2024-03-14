#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <cstddef>

template <typename Key, typename Value>
class HashTable {
public:
    struct Entry {
        Key key;
        Value value;
    };

public:
    class Iterator {
    public:
        typename std::vector<std::vector<Entry>>::iterator outer_iter;
        typename std::vector<Entry>::iterator inner_iter;

        Iterator(typename std::vector<std::vector<Entry>>::iterator iter) : outer_iter(iter) {
            inner_iter = outer_iter->begin();
            if (outer_iter->size() == 0) {
                ++outer_iter;
            }
        };

        Iterator& operator++() {
//            if(*outer_iter.size() != 0) {
//                inner_iter++;
//            }
            while (outer_iter->end() == inner_iter) { //iter over empty bucket
                outer_iter++;
                inner_iter = outer_iter->begin();
            }
            return *this;
        }

        Entry& operator*() {
            return *inner_iter;
        }

        bool operator!=(const Iterator& rhs) {
            if (rhs.inner_iter!=inner_iter or rhs.outer_iter != outer_iter) {
                return true;
            }
            return false;
        }
    };

public:
    HashTable() {
        size = 0;
        capacity = 10;
        storage.resize(capacity);
    }

    HashTable(int s_capacity) {
        size = 0;
        capacity = s_capacity;
        storage.resize(capacity);
    }

    HashTable(const HashTable& other) {
        size = other.size;
        capacity = other.capacity;
        storage = other.storage;
    }

    HashTable(HashTable &&other) {
        size = std::move(other.size);
        capacity = std::move(other.capacity);
        storage = std::move(other.storage);
    }

    bool Insert(const Key& key, const Value& value) {
        int bucket_num = MyHash(Entry{key, value});
        if (storage[bucket_num].size() == 0 ) {
            storage[bucket_num].push_back(Entry{key, value});
            size++;
            if (static_cast<double>(size) / capacity > 0.75) {
                Rehash();
            }
            return true;
        }
        else {
            for (int i=0; i<storage[bucket_num].size(); i++) {
                if (storage[bucket_num][i].key==key) {
                    return false;
                }
            }
            storage[bucket_num].push_back(Entry{key, value});
            size++;
            if (static_cast<double>(size) / capacity > 0.75) {
                Rehash();
            }
            return true;
        }
    }

    std::pair<bool, Value> Find(const Key& key) {
        Value val{};
        int bucket_num = MyHash(Entry{key, val});
        if (storage[bucket_num].size()==0) return std::make_pair(false, val);
        else {
            for (int i=0; i<storage[bucket_num].size(); i++) {
                if (storage[bucket_num][i].key == key) {
                    return std::make_pair(true, storage[bucket_num][i].value);
                }
            }
        }
    }
    bool Remove(const Key& key) {
        Value val{};
        int bucket_num = MyHash(Entry{key, val});
        for (typename std::vector<Entry>::iterator it = storage[bucket_num].begin(); it != storage[bucket_num].end(); ++it) {
            if (it->key == key) {
                storage[bucket_num].erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    Value& operator[](const Key& key) {
        Value val{};
        int bucket_number = MyHash({key, val});
        for (int i=0; i<storage[bucket_number].size(); i++) {
            if (storage[bucket_number][i].key == key) {
                return storage[bucket_number][i].value;
            }
        }
        Entry entry{key, val};
        storage[bucket_number].push_back(entry);
        return storage[bucket_number][storage[bucket_number].size()-1].value;
    }

    size_t Size() const {
        return size;
    }

    auto begin() {
        Iterator it(storage.begin());
        if (storage[0].size() == 0) {
            ++it;
        }
        return it.inner_iter;
    }


    auto end() {
        Iterator it(storage.end());
        while (it.outer_iter->size() == 0) {
            it.outer_iter--;
        }
        it.inner_iter = it.outer_iter -> begin();
        return it.inner_iter;
    };
private:
    size_t capacity, size;
    std::vector<std::vector<Entry>> storage;


    int MyHash(Entry entry) {
        return std::hash<decltype(entry.key)>{}(entry.key) % capacity;
    }

    void Insert(Entry entry, std::vector<std::vector<Entry>>& temp) {
        temp[MyHash(entry)].push_back(entry);
    }

    void Rehash() {
        this->capacity *= 2;
        std::vector<std::vector<Entry>> temp_cp;
        temp_cp.resize(capacity);
        for (int i=0; i<storage.size(); i++) {
            for (int j=0; j<storage[i].size(); j++) {
                Insert(storage[i][j], temp_cp);
            }
        }
        storage = std::move(temp_cp);
    }
};
