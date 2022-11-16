//
// Created by jorge on 15/11/2022.
//

#ifndef KING_TEST_UMAPDATABASE_H
#define KING_TEST_UMAPDATABASE_H
#include <unordered_map>

template <class keyType,class valueType>
class UMapDatabase{
private:
    std::unordered_map<keyType,valueType> umap;
public:
    void add(keyType key, valueType value);
    bool contains(keyType key);
    valueType get(keyType key);
    int getSize();
    //Functions like Remove() should be added too
};


#include "UMapDatabase.tpp"
#endif //KING_TEST_UMAPDATABASE_H
