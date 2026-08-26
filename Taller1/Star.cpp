#include "Star.h"
#include <GL/gl.h>

//---------------------------------------------------------------------------------------------------
Star :: Star ( float radio ) : Object(), radio( radio ) {
    Triangle* t1 = new Triangle( 1.0f, 3 );
    Triangle* t2 = new Triangle( 1.0f, 3 );

    this->AddChild( t1 );
    this->AddChild( t2 );
}
//---------------------------------------------------------------------------------------------------
Star :: ~Star() {};
//---------------------------------------------------------------------------------------------------
void Star :: Draw() {
    glPushMatrix();
        glScalef( this->radio, this->radio, 1.0f );
        glColor3fv( this->Color );
        if ( this->Children.size() > 0 && this->Children[ 0 ] != nullptr ) {
            this->Children[ 0 ]->Draw();
        }

        if ( this-> Children.size() > 1 && this->Children[ 1 ] != nullptr ) {
            glPushMatrix();
                glRotatef( 180.0f, 0.0f, 0.0f, 1.0f );
                this->Children[ 1 ]->Draw();
            glPopMatrix();
        }

        glPopMatrix();
}