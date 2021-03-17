#ifndef CACHE_H
#define CACHE_H

#include <unordered_map>
#include <deque>

using namespace std;

class ICache {
    public:
        virtual string get(int key) = 0;
        virtual void set(int key, string word) = 0;
        virtual int contains(int key) = 0;
};

class LRUCache : public ICache {
    private:
        int capacity;
        unordered_map<int, string> words;
        deque<int> dq;

    public:
        LRUCache(int capacity);
        string get(int key);
        void set(int key, string word);
        int contains(int key);
        int size_cache();
        bool overflow(int size_dq);
};

#endif