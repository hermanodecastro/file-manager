#include <iostream>
#include "filemanager.hpp"

int main() {
    FileManager file("fruits.txt");

    //the first time, word comes from file
    cout << file.get(1) << endl;
    cout << file.get(2) << endl;
    cout << file.get(3) << endl; 
    cout << file.get(4) << endl;
    cout << file.get(5) << endl; 

    //the second time, word comes from  cache
    cout << file.get(1) << endl;
    cout << file.get(2) << endl;
    cout << file.get(3) << endl;
    cout << file.get(4) << endl;
    cout << file.get(5) << endl; 
    
}