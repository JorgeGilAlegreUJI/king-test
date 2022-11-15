//
// Created by jorge on 15/11/2022.
//

#include "../../Exceptions/RuntimeError.h"

template<class keyType, class valueType>
void IuMapDatabase<keyType, valueType>::Add(keyType key, valueType value) {
    umap[key] = value;
}

template<class keyType, class valueType>
bool IuMapDatabase<keyType, valueType>::Contains(keyType key) {
    return umap.count(key) > 0;
}

template<class keyType, class valueType>
valueType IuMapDatabase<keyType, valueType>::Get(keyType key) {
    if(!Contains(key)) throw RuntimeError("Key: "+key +" not found in Database");
    return umap.at(key);
}