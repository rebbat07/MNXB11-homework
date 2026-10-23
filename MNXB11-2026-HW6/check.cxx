#include <iostream>
#include <MovingObject.h>

R__LOAD_LIBRARY(MovingObject_cxx.so)

void check() {
     MovingObject A(0.30, 0.40, 0.00);
    MovingObject B(0.30, 0.40, 0.50);

    std::cout << "A: v = " << A.Speed() << ", vxy = " << A.HorizontalSpeed() << std::endl;
    std::cout << "B: v = " << B.Speed() << ", vxy = " << B.HorizontalSpeed() << std::endl;
}