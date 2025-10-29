#ifndef HASTABLE_H
#define HASTABLE_H
#include <string>
#include <functional>

template <typename KeyTYpe, typename ValueType>
class HashTable {
    private:
    struct Bucket {
        KeyType key;
        ValueType value;
        Bucket* next;
        Bucket(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}
    };
    Bucket** table;
    int capacity;

    int getHashIndex(const KeyType& key) const {
        std::hash<KeyType> hashFunc;
        return hashFunc(key) % capacity;
    }
    public:
    HashTable(int cap = 1000) {
        capacity = cap;
        table = new Bucket*[capacity];
        for (int i = 0; i < capacity; ++i) table[i] = nullptr;
    }
    void insert(const KeyType& key, const ValueType& value) {
        int index = getHashIndex(key);
        Bucket* newBucket = new Bucket(key, value);
        newBucket->next = table[index];
        table[index] = newBucket;
    }
    ValueType* find(const KeyType& key) {
        int index = getHashIndex(key);
        Bucket* curr = table[index];
        while (curr) {
            if (curr->key == key)
            return &curr->value;
        }
        return nullptr;
    }
    ~HashTable() {
        for (int i = 0; i < capacity; ++i){
            Bucket* curr = table[i];
            while (curr) {
                Bucket* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
    };
    #endif
