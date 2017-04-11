//
// Created by Alexander Cochrane on 2017-04-10.
//

#ifndef DATA_STRUCTURES_HASHING_HASHER_H
#define DATA_STRUCTURES_HASHING_HASHER_H

#include <iostream>
#include <string>

#define TABLESIZE 53 // since everybody else is using it

class hasher {
private:
    int collisions = 0;
public:
    struct Node {
        std::string data;
        Node* next = NULL;
        Node(std::string data) {
            this->data = data;
        }
    };

    Node* hashTable[TABLESIZE];

    hasher() {
        for (int i = 0; i < TABLESIZE; i++) {
            hashTable[i] = NULL;
        }
    };

    int hash(std::string data);
    int getCollisions();
    Node*& operator[](int index);
    friend std::ostream& operator<< (std::ostream& out, hasher &h);
    bool search(std::string data);
    void addToHashTable(std::string data, int address);
};


#endif //DATA_STRUCTURES_HASHING_HASHER_H
