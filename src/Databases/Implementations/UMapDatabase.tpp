template<class keyType, class valueType>
void UMapDatabase<keyType, valueType>::add(keyType key, valueType value) {
    umap[key] = value;
}

template<class keyType, class valueType>
bool UMapDatabase<keyType, valueType>::contains(keyType key) {
    return umap.count(key) > 0;
}

template<class keyType, class valueType>
valueType& UMapDatabase<keyType, valueType>::get(keyType key) {
    if(!contains(key)) throw RuntimeError("Key: " + key + " not found in Database");
    return umap.at(key);
}

template<class keyType, class valueType>
unsigned long long UMapDatabase<keyType, valueType>::getSize() {
    return umap.size();
}

template<class keyType, class valueType>
void UMapDatabase<keyType, valueType>::Remove(keyType key) {
    umap.erase(key);
}
