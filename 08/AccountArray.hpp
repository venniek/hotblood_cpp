#ifndef ACCOUNTARRAY_H
#define ACCOUNTARRAY_H

#include "Account.hpp"
typedef Account* ACCPTR;

class BoundCheckAccountPtrArray {
private:
    ACCPTR *arr;
    int arrlen;
public:
    int getArrlen() const;

    ACCPTR &operator[](int idx);
    ACCPTR operator[](int idx) const;

    BoundCheckAccountPtrArray(int len);
    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& copy);
    BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& origin);
    ~BoundCheckAccountPtrArray();
};

#endif