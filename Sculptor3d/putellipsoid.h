#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "geometricfigure.h"
#include "sculptor.h"

class PutEllipsoid : public GeometricFigure{
protected:
    int centroX, centroY, centroZ , raioX, raioY, raioZ, dx, dy, dz;
    float r ,g, b, alpha;
public:
    PutEllipsoid(int dxe,int dye,int dze,int centroXe,int centroYe,int centroZe,int raioXe
                 ,int raioYe,int raioZe, float re, float ge, float be,float alphae);
    ~PutEllipsoid();
    void draw(Sculptor &d);
};

#endif // PUTELLIPSOID_H
