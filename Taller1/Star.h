#include <cstdlib>
#include "Object.h"
#include "Triangle.h"

class Star : public Object {
    protected:
        float radio { 1.0f };
    public:
        Star( float radio = 1.0f );
        virtual ~Star();
        virtual void Draw() override;
};