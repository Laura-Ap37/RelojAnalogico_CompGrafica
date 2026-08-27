// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __pujOpenGL__Hand__h__
#define __pujOpenGL__Hand__h__

#include <functional>

#include "Square.h"
#include "Object.h"

/**
 */
class Hand
  : public Square
{
public:
  Hand( float length, std::function< float( ) > f, Object* decoration = nullptr , float rpm = 0, float decorationSize = 1   );
  virtual ~Hand( ) override;

  virtual void Draw( ) override;
  void Rotate( float angle );
  static void ChangeDecorationSpeed( float amount );
  static void ResetDecorationSpeed( );
  

protected:
  float Length { 1 };
  std::function< float( ) > Function { []( ) -> int { return( 0 ); } };

  Object* Decoration { nullptr };
  float RPM { 0 };
  float RawLength { 1 };
  float SpinAngle { 0 };
  float DecorationSize { 1 };
  inline static float SpeedMultiplier { 1.0f };
};

#endif // __pujOpenGL__Hand__h__

// eof - Hand.h
