#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "geometricfigure.h"
#include "sculptor.h"

class PutSphere : public GeometricFigure{
protected:
    int centroX, centroY, centroZ, raio, dx, dy, dz;
    float r, g, b, alpha;
public:
    PutSphere(int dxe, int dye, int dze, int centroXe, int centroYe, int centroZe, int raioe,
              float re, float ge, float be, float alphae);
    ~PutSphere();
    void draw(Sculptor &d);
};

#endif // PUTSPHERE_H
