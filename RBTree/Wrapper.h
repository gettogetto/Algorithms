#ifndef WRAPPER_H_INCLUDED
#define WRAPPER_H_INCLUDED

#include "MyException.h"

template <typename Object>
class Gref
{
public:
    Gref(): obj(NULL) {}
    explicit Gref(const Object &x)
        : obj(& x) {}

    const Object &get() const
    {
        if (isNull())
            throw NullPointerException();
        else
            return * obj;
    }

    bool isNull() const
    {
        if (obj == NULL)
            return true;
        return false;
    }

private:
    const Object * obj;
};

#endif // WRAPPER_H_INCLUDED
