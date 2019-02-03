#include "Parser.hpp"
#include <stdexcept>
#include <iostream>

int main()
{
    parser::Parser toto("adder.nts");
    toto.LetsParse();
    return 0;
}


// try {
//     if (std::string(av[1]) == std::string("toto")) {
//         throw std::invalid_argument("Toto ce n'est pas original !! :-(");
//     }
// }
// catch(const std::invalid_argument& toto) {
//     std::cerr << "Exception: " << toto.what() << std::endl;
// }
