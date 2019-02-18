#include <exception>
#include <iostream>

class ErrorNano : public std::exception
{
public:
    ErrorNano(const std::string &msg) noexcept : _msg(msg)
    {}
    const char *what() const noexcept override
    {
        return _msg.data();
    }
private:
    std::string _msg;
};
