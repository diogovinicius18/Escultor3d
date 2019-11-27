#ifndef CUTBOX_H
#define CUTBOX_H

#include "sculptor.h"
#include "geometricfigure.h"

class CutBox : public GeometricFigure{
protected:
    int xi, yi, zi, xf, yf, zf,dx,dy,dz;
public:
    CutBox(int dxe,int dye,int dze,int xie,int yie,int zie,int xfe,int yfe,int zfe);
    ~CutBox();
    void draw(Sculptor &d);
};

#endif // CUTBOX_H
