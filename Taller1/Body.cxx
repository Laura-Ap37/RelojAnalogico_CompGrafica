// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Body.h"
#include <GL/gl.h>

// -------------------------------------------------------------------------
Body::
Body( float r, unsigned int s )
  : Circle( s ),
    Radius( r )
{
}

// -------------------------------------------------------------------------
Body::
~Body( )
{
}

// -------------------------------------------------------------------------
void Body::
SetBackgroundColor( float r, float g, float b )
{
  this->BackgroundColor[ 0 ] = r;
  this->BackgroundColor[ 1 ] = g;
  this->BackgroundColor[ 2 ] = b;
}

void Body::
Draw( )
{
  glScalef( this->Radius, this->Radius, 1 );         

  glColor3f( this->BackgroundColor[ 0 ], this->BackgroundColor[ 1 ], this->BackgroundColor[ 2 ] );
  glBegin( GL_TRIANGLE_FAN );
  glColor3f( 1.0, 0.8, 0.86 );      // color del centro
  glVertex2f( 0, 0 );
    for ( unsigned int i = 0; i < this->Points.size( ); i += 2 )
    {
      glColor3fv( this->BackgroundColor );
      glVertex2f( this->Points[ i ], this->Points[ i + 1 ]);
    }

    glColor3fv( this->BackgroundColor );
    glVertex2f( this->Points[ 0 ], this->Points[ 1 ] );
  glEnd( );

  this->Circle::Draw( );
}

// eof - Body.cxx
