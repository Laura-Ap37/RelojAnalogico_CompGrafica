#include "Circle.h"

class Hexagono : public Circle {
    protected:
        float radio { 1.0f };
    public:
    Hexagono( float r, unsigned int s = 6);
    virtual ~Hexagono() override;
    virtual void Draw() override;
};