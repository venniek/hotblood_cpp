#include "AccountArray.hpp"
#include <iostream>
using namespace std;

int BoundCheckAccountPtrArray::getArrlen() const {
    return arrlen;
}

Account* &BoundCheckAccountPtrArray::operator[](int idx) {
    if (idx < 0 || idx >= arrlen) {
        cout << "잘못된 인덱스 접근입니다." << endl;
        return NULL;
    }
    else
        return arr[idx];
}

Account* BoundCheckAccountPtrArray::operator[](int idx) const {
    if (idx < 0 || idx >= arrlen) {
        cout << "잘못된 인덱스 접근입니다." << endl;
        return NULL;
    }
    else
        return arr[idx];
}

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len): arrlen(len) {
    arr = new ACCPTR[arrlen];
}

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& copy) {
    *this = copy;
}

BoundCheckAccountPtrArray& BoundCheckAccountPtrArray::operator=(const BoundCheckAccountPtrArray& origin) {
    if (this != &origin) {
        arrlen = origin.getArrlen();
        if (arr)
            delete []arr;
        arr = new ACCPTR[arrlen];
    }
    return *this;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
    delete []arr;
}
