#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;


template <typename Key, typename Value>
    Value& GetRefStrict(map<Key, Value>& source_dict, Key source_key) {
        for (auto &item: source_dict) {
            if (item.first == source_key) {
                return item.second;
            }
        }
        throw runtime_error("");
    }