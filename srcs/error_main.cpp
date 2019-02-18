#include "error.hpp"

int main()
{
    try {
        throw ErrorNano("toto");
    }
    catch (const ErrorNano str)
    {
        std::cout << "Ah ouais quand même !" << std::endl;
    }
    return (0);
}
