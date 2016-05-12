#ifndef MYEXCEPTION_H_INCLUDED
#define MYEXCEPTION_H_INCLUDED

#include <string>

class DSException
{
public:
    typedef std::string string;

public:
    DSException(const string &_msg = string())
        :message(_msg) {}
    virtual ~DSException() {}


    virtual string what() const
    {
        return message;
    }
    virtual string toString() const
    {
        return "Exception " + message;
    }

private:
    string message;
};

class DuplicateItemException : public DSException
{
public:
    DuplicateItemException(const string &_msg = string())
        : DSException(_msg) {}
};

class NullPointerException : public DSException
{
public:
    NullPointerException(const string &_msg = string())
        : DSException(_msg) {}
};

#endif // MYEXCEPTION_H_INCLUDED
