#include "cutbox.h"

CutBox::CutBox(int dxe,int dye,int dze,int xie,int yie,int zie,int xfe,int yfe,int zfe){
    xi=xie;
    yi=yie;
    zi=zie;
    xf=xfe;
    yf=yfe;
    zf=zfe;
    dx=dxe;
    dy=dye;
    dz=dze;
}
CutBox::~CutBox(){

}
void CutBox::draw(Sculptor &d){

    int aux;

    if(xi>xf){
        aux = xi;
        xi = xf;
        xf = aux;
    }
    if(xi<0)
        xi = 0;
    if(xf > dx)
        xf = dx;

    if(yi>yf){
        aux = yi;
        yi = yf;
        yf = aux;
    }

    if(yi<0)
        yi = 0;
    if(yf > dy)
        yf = dy;

    if(zi>zf){
        aux = zi;
        zi = zf;
        zf = aux;
    }

    if(zi<0)
        zi = 0;
    if(zf > dz)
        zf = dz;

    for(int i=xi; i<xf; i++)
        for(int j=yi; j<yf; j++)
            for(int k=zi; k<zf; k++)
                d.CutVoxel(i,j,k);
}
