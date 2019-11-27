#ifndef CUTVOXEL_H
#define CUTVOXEL_H


#include "geometricfigure.h"


class CutVoxel : public GeometricFigure
{
protected:
    int x, y, z;
public:
    CutVoxel(int xe,int ye,int ze);
    ~CutVoxel();
    void draw(Sculptor &d);
};


#endif // CUTVOXEL_H
