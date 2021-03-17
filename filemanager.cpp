#include <iostream>
#include <memory>
#include <fstream>
#include "filemanager.hpp"
#include "exception.hpp"

using namespace std;

FileManager::FileManager(string path) {
    this->path = path;
    this->cache = make_unique<LRUCache>(1024); //1kb;
}

// Read a word from the file.
// Throws an exception if it cannot open the file 
// or if there is no word corresponding to the index passed as an argument.
string FileManager::get_word_from_file(int index) {
    ifstream file(this->path);
    try {
        if(file.is_open()) {
            int count = 0;
            string line;

            while(!file.eof()) {
                getline(file, line, '\n');
                if(count == index) {
                    file.close();
                    return line;
                }
                count++;
            }

            file.close();
            throw NoSuchIndexException();

        } else {
            throw NoSuchFileException();
        }

    } catch(NoSuchFileException &e) {
        cerr << e.what();
    } catch(NoSuchIndexException &e) {
        cerr << e.what();
    }
}

// If the string is not in cache, returns it from file and store it in cache, otherwise, returns it from cache.
string FileManager::get(int key) {
    if(this->cache->contains(key)) {
        return this->cache->get(key);
    } else {
        string word = this->get_word_from_file(key); 
        this->cache->set(key, word);
        return word;
    }
}
