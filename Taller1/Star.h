#include <cstdlib>
#include "Object.h"
#include "Triangle.h"

class Star : public Object {
    public:
        Star( float radio = 1.0f );
        virtual ~Star();
};