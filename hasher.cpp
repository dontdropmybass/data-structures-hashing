//
// Created by Alexander Cochrane on 2017-04-10.
//

#include "hasher.h"

int hasher::hash(std::string data) {
    int sum = 127345; // the unicode point (in decimal) of 🅱️
    for (int i = 0; i < data.length(); i++) {
        sum += ((int) data.c_str()[i]);
    }

    int address = sum % TABLESIZE;

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

    return address;
}

int hasher::getCollisions() {
    return collisions;
}

hasher::Node *&hasher::operator[](int index) {
    if (index > TABLESIZE) throw std::invalid_argument("Yo that's too much dude");
    return hashTable[index];
}

std::ostream& operator<<(std::ostream &out, hasher &h) {
    for (int i = 0; i < TABLESIZE; i++) {
        out << std::string("Bucket #") << i << std::string(":");
        if (h[i] == NULL) {
            out << std::string(" NULL");
        }
        else {
            hasher::Node* node = h[i];
            while (node != NULL) {
                out << std::string(" ") << node->data;
                node = node->next;
            }
        }
        out << std::endl;
    }

    return out;
}
