// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Callbacks.h"
#include "App.h"
#include "Hand.h"

#include <GL/glut.h>

// -------------------------------------------------------------------------
void cb_draw( )
{
  clockWorld.Draw( );
  glutSwapBuffers( );
}

// -------------------------------------------------------------------------
void cb_idle( )
{
  glutPostRedisplay( );
}

// -------------------------------------------------------------------------
void cb_resize( int w, int h )
{
  clockWorld.Resize( w, h );
  glutPostRedisplay( );
}

// -------------------------------------------------------------------------
void cb_keyboard( unsigned char k, int x, int y )
{
  if( k == 27 ){
    std::exit (1);
  }

  if( k == '+' || k == '=' ) {
    Hand::ChangeDecorationSpeed( 2.0f );
  }

  if( k == '-' ) {
    Hand::ChangeDecorationSpeed( -2.0f );
  }
}

// -------------------------------------------------------------------------
void cb_keyboard_up( unsigned char k, int x, int y )
{
  if( k == '+' || k == '=' || k == '-' ) {
    Hand::ResetDecorationSpeed( );
  }
}

// -------------------------------------------------------------------------
void cb_special_keyboard( int k, int x, int y )
{
}

// eof - Callbacks.cxx
