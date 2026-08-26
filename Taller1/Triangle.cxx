#include "Triangle.h"
#include <GL/gl.h> 

// -------------------------------------------------------------------------
Triangle::
Triangle( float r, unsigned int s )
  : Circle( s ),
    Radius( r )
{
}

// -------------------------------------------------------------------------
Triangle::
~Triangle( )
{
}

// -------------------------------------------------------------------------
void Triangle::
Draw( )
{
  glPushMatrix();
    glScalef( this->Radius, this->Radius, 1 );
    this->Circle::Draw( );
  glPopMatrix();
}

// eof - Triangle
