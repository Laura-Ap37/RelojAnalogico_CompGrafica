// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Hand.h"

#include <cmath>
#include <GL/gl.h>

// -------------------------------------------------------------------------
Hand::
Hand( float length, std::function< float( ) > f, Object* decoration, float rpm, float decorationSize )
  : Square( ),
    Length( length / std::sqrt( float( 2 ) ) ),
    Function( f ),
    Decoration( decoration ),
    RPM( rpm ),
    RawLength( length ),
    SpinAngle( 0 ),
    DecorationSize( decorationSize )
{
}

// -------------------------------------------------------------------------
Hand::
~Hand( )
{
}

// -------------------------------------------------------------------------
void Hand::
Draw( )
{
  float a = this->Function( );

  glPushMatrix( );
    glRotatef( a, 0, 0, 1 );
    glScalef( this->Length * 0.08, this->Length, 1 );
    glRotatef( 45, 0, 0, 1 );
    glTranslatef( 0.5, 0.5, 0 );
    this->Square::Draw( );
  glPopMatrix( );

  if (this ->Decoration != nullptr)
  {
    this->SpinAngle += this->RPM * Hand::SpeedMultiplier * (this->RawLength / 10.0f);

    glPushMatrix( );
      glRotatef( a, 0, 0, 1 );              //mismo angulo de la manecilla
      glTranslatef(0, this->RawLength, 0);  //sube hasta la punta de la manecilla
      glRotatef(this->SpinAngle, 0, 0, 1); //gira la figura
      glScalef(this->DecorationSize, this->DecorationSize, 1); //escala el triangulo
      this->Decoration->Draw( );
    glPopMatrix( );
  }
}
//---------------------------------------------------------------------------------------------------
void Hand :: Rotate( float angle ) {
  this->SpinAngle += angle;
}

//---------------------------------------------------------------------------------------------------
void Hand :: ChangeDecorationSpeed( float amount ) {
  Hand::SpeedMultiplier += amount;

  if ( Hand::SpeedMultiplier < 0.0f ) {
    Hand::SpeedMultiplier = 0.0f;
  }
}

//---------------------------------------------------------------------------------------------------
void Hand :: ResetDecorationSpeed( ) {
  Hand::SpeedMultiplier = 1.0f;
}

// eof - Hand.cxx
