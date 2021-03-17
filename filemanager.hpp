#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <memory>
#include <string>
#include "cache.hpp"

using namespace std;

class FileManager {
    private:
        string path;
        unique_ptr<ICache> cache;

        string get_word_from_file(int key);

    public:
        FileManager(string path);
        string get(int key);
};

#endif