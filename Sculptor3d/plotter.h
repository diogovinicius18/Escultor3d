#ifndef PLOTTER_H
#define PLOTTER_H

#include "geometricfigure.h"
#include "sculptor.h"
#include <QWidget>
#include <QString>
#include "vector"


class Plotter : public QWidget
{
    Q_OBJECT

private:
    vector<vector<Voxel>> aux;
    int dx, dy, dz;
    int dimX, dimY, dimZ;
    int r, g, b, t;
    int mouseX, mouseY;
    int tamBoxX, tamBoxY, tamBoxZ;
    int tamEllipseX, tamEllipseY, tamEllipseZ;
    int raioSphere;

    QString plano, metodo;

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
   //void mouseReleaseEvent(QMouseEvent *event);

    Sculptor *escultura;
    vector<GeometricFigure*>fig;
    GeometricFigure *a;

signals:
    void posMouseX(int);
    void posMouseY(int);

public slots:
    void setProfundidade (int profundidadeE);
    void setPlanoXY();
    void setPlanoXZ();
    void setPlanoYZ();
    void setTamBoxX(int ent);
    void setTamBoxY(int ent);
    void setTamBoxZ(int ent);
    void setRaioSphere(int raio);
    void setRaioEllipeseX(int rX);
    void setRaioEllipeseY(int rY);
    void setRaioEllipeseZ(int rZ);
    void setColorR(int red);
    void setColorG(int green);
    void setColorB(int blue);
    void setPutMetodoVoxel();
    void setPutMetodoBox();
    void setPutMetodoSphere();
    void setPutMetodoEllipse();
    void setPutMetodoCutVoxel();
    void setPutMetodoCutBox();
    void setPutMetodoCutSphere();
    void setPutMetodoCutEllipse();
    void putDraw();


};

#endif // PLOTTER_H
