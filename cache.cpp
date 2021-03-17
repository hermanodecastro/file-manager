#include "cache.hpp"

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
}

// Returns the cache string
string LRUCache::get(int key) {
    deque<int>::iterator iter = dq.begin();

    while(*iter != key) {
        iter++;
    }

    this->dq.erase(iter);
    this->dq.push_front(key);
     
    // Only for demo
    return "From Cache: " + this->words[key]; 
    //return this->words[key];   
}

// First, checks if the key is not in the cache. 
// If key is not in the cache, checks if adding a new string will cause an oveflow in the cache.
// If it causes overflow, removes the last element from the deque and delete the word from the hashmap,
// if not, just add the new word to the cache and insert the key in the first position of the deque.
void LRUCache::set(int key, string word) {
    if(!this->contains(key)) {
        if(this->overflow(this->size_cache())) {
            int last = this->dq.back();
            this->dq.pop_back();
            this->words.erase(last);
        }
    } else {
        deque<int>::iterator iter = this->dq.begin();

        while(*iter != key) {
            iter++;
        }

        this->dq.erase(iter);
        this->words.erase(key);
    }

    this->dq.push_front(key);
    this->words[key] = word;
}

// Checks if the key is already in the cache.
int LRUCache::contains(int key) {
    return this->words.count(key);
}

// Returns the size of the current cache.
int LRUCache::size_cache() {
    return this->words.size() * sizeof(unordered_map<int, string>::value_type);
}

// Checks if the next string added to the cache will cause an overflow.
bool LRUCache::overflow(int size_dq) {
    return this->size_cache() + sizeof(string) > (unsigned) this->capacity;
}
