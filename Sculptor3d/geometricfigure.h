#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

#include <sculptor.h>

class GeometricFigure
{
public:
    GeometricFigure();
    virtual ~GeometricFigure();
    virtual void draw(Sculptor &d)=0;
};

#endif // GEOMETRICFIGURE_H
