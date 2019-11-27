#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include "vector"
#include <QString>

using namespace std;

struct Voxel {
  float vermelho=255,verde=0,azul=0, transparencia;
  bool temBloco;
};

class Sculptor{
protected:
    Voxel ***v;
    int nLinhas, nColunas,nPlanos;
    float r, g, b, a;
public:
    Sculptor(int xe,int ye,int ze);
    ~Sculptor();
    void SetColor(float r,float g,float b,float a);
    void PutVoxel(int x,int y,int z);
    void CutVoxel(int x,int y,int z);
    void WriteOFF(string arquivo);
    void WriteVECT(string arquivo);
    vector<vector<Voxel>> MostrarPlano(int profundidade, QString plano);
};

#endif // SCULPTOR_H
