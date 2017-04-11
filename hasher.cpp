//
// Created by Alexander Cochrane on 2017-04-10.
//

#include "hasher.h"

int hasher::hash(std::string data) {
    int sum = 127345; // the unicode point (in decimal) of 🅱️
    for (int i = 0; i < data.length(); i++) {
        sum += ((int) data.c_str()[i]);
    }
    return sum % TABLESIZE;
}

int hasher::getCollisions() {
    return collisions;
}

hasher::Node *&hasher::operator[](int index) {
    if (index > TABLESIZE) throw std::invalid_argument("Yo that's too much dude");
    return hashTable[index];
}

bool hasher::search(std::string data) {
    int address = hash(data);
    Node* node = hashTable[address];
    while (node != NULL) {
        if (node->data == data) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void hasher::addToHashTable(std::string data, int address) {
    if (hashTable[address] != NULL) {
        collisions++;
        Node* node = hashTable[address];
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new Node(data);
    }
    else {
        hashTable[address] = new Node(data);
    }
}
