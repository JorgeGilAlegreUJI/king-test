#ifndef KING_TEST_UMAPDATABASE_H
#define KING_TEST_UMAPDATABASE_H
#include <unordered_map>
#include "../../Exceptions/RuntimeError.h"

template <class keyType,class valueType>
class UMapDatabase{
private:
    std::unordered_map<keyType,valueType> umap;
public:
    void add(keyType key, valueType value);
    void Remove(keyType key);
    bool contains(keyType key);
    valueType& get(keyType key);
    unsigned long long getSize();
};


#include "UMapDatabase.tpp"
#endif //KING_TEST_UMAPDATABASE_H
