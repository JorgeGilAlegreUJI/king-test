//
// Created by jorge on 15/11/2022.
//

#ifndef KING_TEST_IUMAPDATABASE_H
#define KING_TEST_IUMAPDATABASE_H
#include <unordered_map>

template <class keyType,class valueType>
class IuMapDatabase{
private:
    std::unordered_map<keyType,valueType> umap;
public:
    void Add(keyType key,valueType value);
    bool Contains(keyType key);
    valueType Get(keyType key);
    //Functions like Remove() should be added too
};


#include "IuMapDatabase.tpp"
#endif //KING_TEST_IUMAPDATABASE_H
