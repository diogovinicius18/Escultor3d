#include "cutvoxel.h"

CutVoxel::CutVoxel(int xe,int ye,int ze){
    x = xe;
    y = ye;
    z = ze;
}
CutVoxel::~CutVoxel(){

}
void CutVoxel::draw(Sculptor &d){
    d.CutVoxel(x, y, z);
}
