#pragma once
#include <string>

template<class T>
class Result
{
public:
    bool valid = false;
    T value;
    std::string error = "Success";
    explicit operator bool() const
    {
        return valid;
    }
    // get that dereference
};

