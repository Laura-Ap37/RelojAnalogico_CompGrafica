#include <cstdlib>
#include "Hexagono.h"
#include <GL/gl.h>

//---------------------------------------------------------------------------------------------------
Hexagono :: Hexagono( float r, unsigned int s ) : Circle( s ), radio( r ) {}
//---------------------------------------------------------------------------------------------------
Hexagono :: ~Hexagono() {}
//---------------------------------------------------------------------------------------------------
void Hexagono :: Draw() {
    glPushMatrix();
        glScalef( this->radio, this->radio, 1 );
        this->Circle::Draw();
    glPopMatrix();
}