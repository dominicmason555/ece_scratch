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
    T& operator*() {
        return value;
    }
    T* operator->()
    {
        return &value;
    }
    friend std::ostream &operator<<(std::ostream &out, const Result<T> &res)
    {
        if (res.valid)
            out << res.value;
        return out;
    }
};

