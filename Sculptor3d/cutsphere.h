#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "geometricfigure.h"
#include "sculptor.h"


class CutSphere : public GeometricFigure{
protected:
    int centroX, centroY, centroZ, raio, dx, dy, dz;
public:
    CutSphere(int dxe, int dye,int dze,int centroXe,int centroYe,int centroZe,int raioe);
    ~CutSphere();
    void draw(Sculptor &d);
};

#endif // CUTSPHERE_H
