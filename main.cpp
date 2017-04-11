#include <iostream>
#include "dictionary.h"
#include "hasher.h"

int main() {
    hasher h;
    dictionary d("/Users/alex/repos/data-structures-searching-and-trees/dictionary.txt");
    for (int i = 0; i < d.size(); i++) {
//        std::cout << d[i] << std::endl;
        h.hash(d[i]);
    }

//    std::cout << "There are " << h.getCollisions() << " collisions." << std::endl;
//
//    int numEmptyBuckets = 0;
//    for (int i = 0; i < TABLESIZE; i++) {
//        if (h[i] == NULL) {
//            numEmptyBuckets++;
//        }
//    }
//
//    std::cout << "There are also " << numEmptyBuckets << " empty buckets." << std::endl;

    std::cout << h << std::endl;

    return 0;
}