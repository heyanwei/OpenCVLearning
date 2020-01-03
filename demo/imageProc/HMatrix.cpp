#include "HMatrix.h"

#include <stdio.h>
#include <iostream>

namespace image
{
HMatrix::HMatrix()
{
    std::cout << "HMatrix init..." << std::endl;
}

HMatrix::~HMatrix()
{
    std::cout << "HMatrix end..." << std::endl;
}

} // namespace image