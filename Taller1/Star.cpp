#include "Star.h"

//---------------------------------------------------------------------------------------------------
Star :: Star( float radio ) : Object() {
    Triangle* t1 = new Triangle( radio, 3 );
    Triangle* t2 = new Triangle ( radio, 3 );

    this->AddChild( t1 );
    this->AddChild( t2 );
};
//---------------------------------------------------------------------------------------------------
Star :: ~Star() {};