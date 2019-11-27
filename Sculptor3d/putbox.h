#ifndef PUTBOX_H
#define PUTBOX_H


#include "geometricfigure.h"
#include "sculptor.h"

class PutBox : public GeometricFigure{
protected:
    int xi, yi, zi, xf, yf, zf, dx, dy, dz;
    float r, g, b, alpha;
public:
    PutBox(int dxe,int dye,int dze,int xie,int yie,int zie,int xfe,int yfe,int zfe,float re,float ge,float be,float alphae);
    ~PutBox();
    void draw(Sculptor &d);
};
#endif // PUTBOX_H
