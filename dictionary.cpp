//
// Created by Alexander Cochrane on 2017-04-10.
//

#include <regex>
#include <sstream>
#include "dictionary.h"

dictionary::dictionary() {/* empty public constructor */}

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
        ifs >> tempString;
        std::stringstream result;
        std::regex nonLetterCharacters("[^a-zA-Z]");
        std::regex_replace(std::ostream_iterator<char>(result), tempString.begin(), tempString.end(), nonLetterCharacters, "");
        tempString = result.str();
        std::transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
        array[length-1] = tempString;
        delete [] temp;
    }
}

int dictionary::size() {
    return this->length;
}

std::string &dictionary::operator[](int index) {
    return array[index];
}

void dictionary::add(std::string data) {
    temp = new std::string[length];
    for (int i = 0; i < length; i++) {
        temp[i] = array[i];
    }
    length++;
    array = new std::string[length];
    for (int i = 0; i < length-1; i++) {
        array[i] = temp[i];
    }
    std::stringstream result;
    std::regex nonLetterCharacters("[^a-zA-Z]");
    std::regex_replace(std::ostream_iterator<char>(result), data.begin(), data.end(), nonLetterCharacters, "");
    data = result.str();
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    array[length-1] = data;
    delete [] temp;
}
