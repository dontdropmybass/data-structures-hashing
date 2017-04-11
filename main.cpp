#include <iostream>
#include "dictionary.h"
#include "hasher.h"

std::ostream& operator<<(std::ostream &out, hasher &h) {
    for (int i = 0; i < TABLESIZE; i++) {
        out << std::string("Bucket #") << i + 1 << std::string(":");
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

int main() {
    hasher h;
    dictionary d("/Users/alex/repos/data-structures-searching-and-trees/dictionary.txt");
    dictionary other("/Users/alex/repos/data-structures-searching-and-trees/misspelled.txt");
    dictionary misspelled;
    for (int i = 0; i < d.size(); i++) {
//        std::cout << d[i] << std::endl;
        int address = h.hash(d[i]);
        h.addToHashTable(d[i], address);
    }

    std::cout << "There are " << h.getCollisions() << " collisions." << std::endl;

    int numEmptyBuckets = 0;
    for (int i = 0; i < TABLESIZE; i++) {
        if (h[i] == NULL) {
            numEmptyBuckets++;
        }
    }

    std::cout << "There are also " << numEmptyBuckets << " empty buckets." << std::endl;

    std::cout << h << std::endl;

    for (int i = 0; i < other.size(); i++) {
        if (!h.search(other[i]) && other[i] != "") {
            misspelled.add(other[i]);
        }
    }

    std::cout << "Misspelled words:" << std::endl;

    for (int i = 0; i < misspelled.size(); i++) {
        std::cout << "\t" << misspelled[i] << std::endl;
    }

    return 0;
}