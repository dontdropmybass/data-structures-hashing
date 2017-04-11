//
// Created by Alexander Cochrane on 2017-04-10.
//

#ifndef DATA_STRUCTURES_HASHING_FILELOADER_H
#define DATA_STRUCTURES_HASHING_FILELOADER_H

#include <fstream>
#include <string>

class dictionary {
private:
    std::string* array;
    std::string* temp;
    int length = 0;
public:
    dictionary(std::string filename);
    int size();
    std::string& operator[] (int index);
};


#endif //DATA_STRUCTURES_HASHING_FILELOADER_H
