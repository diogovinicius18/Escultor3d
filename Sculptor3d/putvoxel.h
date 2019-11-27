#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "geometricfigure.h"
#include "sculptor.h"

class PutVoxel : public GeometricFigure{
protected:
    int x, y, z;
    float r, g, b, alpha;
public:
    PutVoxel(int xe,int ye,int ze, float re, float ge, float be, float alphae);
    ~PutVoxel();
    void draw(Sculptor &d);
};

#endif // PUTVOXEL_H
