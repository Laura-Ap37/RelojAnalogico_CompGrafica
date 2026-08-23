#include "Triangle.h"

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
  glScalef( this->Radius, this->Radius, 1 );
  this->Circle::Draw( );
}

// eof - Triangle
