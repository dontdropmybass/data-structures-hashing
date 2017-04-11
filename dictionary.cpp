//
// Created by Alexander Cochrane on 2017-04-10.
//

#include "dictionary.h"
dictionary::dictionary(std::string filename) {
    std::ifstream ifs(filename, std::fstream::in);
    if (ifs.fail()) {
        throw std::invalid_argument("Bad filename");
    }

    while (!ifs.eof()) {
        temp = new std::string[length];
        for (int i = 0; i < length; i++) {
            temp[i] = array[i];
        }
        length++;
        array = new std::string[length];
        for (int i = 0; i < length-1; i++) {
            array[i] = temp[i];
        }
        ifs >> array[length-1];
        delete [] temp;
    }
}

int dictionary::size() {
    return this->length;
}

std::string &dictionary::operator[](int index) {
    return array[index];
}
