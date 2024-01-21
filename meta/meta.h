//
// Created by erikp on 1/21/2024.
//

#include <utility>

template<typename VALUE>
class Result {
public:
    bool ok = false;
    VALUE value;
};

template<typename VALUE>
Result<VALUE> MakeResult(bool status, VALUE result) {
    Result<VALUE> tmp;
    tmp.ok = status;
    tmp.value = result;
    return tmp;

}

template<typename VALUE>
Result<VALUE> MakeResult() {
    Result<VALUE> tmp;
    tmp.ok = false;
    return tmp;

}