#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <QMainWindow>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QDebug>
#include <QMouseEvent>
#include "geometricfigure.h"
#include "plotter.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"




Plotter::Plotter(QWidget *parent) : QWidget(parent){
    escultura = new Sculptor(30,30,30);
    dx = 30;
    dy = 30;
    dz = 30;
    r = 100;
    g = 0;
    b = 0;
    t = 1;
    dimX = 30;
    dimY = 30;
    dimZ = 30;
    mouseX = 5;
    mouseY = 5;
    tamBoxX = 3;
    tamBoxY = 3;
    tamBoxZ = 3;
    tamEllipseX = 1;
    tamEllipseY = 1;
    tamEllipseZ = 1;
    raioSphere = 1;

    metodo = "putVoxel";
    plano = "PlanoXY";
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    pen.setColor(QColor(100));
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(255,255,255,100));
    painter.setPen(pen);
    painter.setBrush(brush);


    if(plano == "PlanoXY"){
        for(int k=0; k<dz; k++){
            aux=escultura->MostrarPlano(k, plano);
            for(int i = 0; i < dx; i++){
                for(int j = 0; j < dy; j++){
                    if(k==dimZ-1){
                        brush.setColor(QColor(255,255,255));
                        pen.setColor(QColor(100));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dx)+k*50/dz,j*((height()-50)/dy)+k*50/dz,(width()-50)/dx,(height()-50)/dy);
                    }
                    else{
                        brush.setColor(QColor(255,255,255,0));
                        pen.setColor(QColor(100,100,100,20));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dx)+k*50/dz,j*((height()-50)/dy)+k*50/dz,(width()-50)/dx,(height()-50)/dy);
                    }
                    if(aux[i][j].temBloco){
                        if(k==dimZ-1){
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dx)+k*50/dz,j*((height()-50)/dy)+k*50/dz,(width()-50)/dx,(height()-50)/dy);
                        }
                        else{
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul,20));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dx)+k*50/dz,j*((height()-50)/dy)+k*50/dz,(width()-50)/dx,(height()-50)/dy);
                        }
                    }
                }
            }
        }
    }
    if(plano == "PlanoXZ"){
        for(int k=0; k<dy; k++){
            aux=escultura->MostrarPlano(k, plano);
            for(int i = 0; i < dx; i++){
                for(int j = 0; j < dz; j++){
                    if(k==dimY-1){
                        brush.setColor(QColor(255,255,255));
                        pen.setColor(QColor(100));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dx)+k*50/dy,j*((height()-50)/dz)+k*50/dy,(width()-50)/dx,(height()-50)/dz);
                    }
                    else{
                        brush.setColor(QColor(255,255,255,0));
                        pen.setColor(QColor(100,100,100,20));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dx)+k*50/dy,j*((height()-50)/dz)+k*50/dy,(width()-50)/dx,(height()-50)/dz);
                    }
                    if(aux[i][j].temBloco){
                        if(k==dimY-1){
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dx) + k*50/dy + 50/(2*dy), j*((height()-50)/dz)+k*50/dy + 50/(2*dy), (width()-50)/dx, (height()-50)/dz);
                        }
                        else{
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul,20));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dx) + k*50/dy + 50/(2*dy), j*((height()-50)/dz)+k*50/dy + 50/(2*dy),(width()-50)/dx, (height()-50)/dz);
                        }
                    }
                }
            }
        }
    }
    if(plano == "PlanoYZ"){
        for(int k=0; k<dx; k++){
            aux=escultura->MostrarPlano(k, plano);
            for(int i = 0; i < dy; i++){
                for(int j = 0; j < dz; j++){
                    if(k==dimX-1){
                        brush.setColor(QColor(255,255,255));
                        pen.setColor(QColor(100));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dy)+k*50/dx,j*((height()-50)/dz)+k*50/dx,(width()-50)/dy,(height()-50)/dz);
                    }
                    else{
                        brush.setColor(QColor(255,255,255,0));
                        pen.setColor(QColor(100,100,100,20));
                        painter.setPen(pen);
                        painter.setBrush(brush);
                        painter.drawRect(i*((width()-50)/dy)+k*50/dx,j*((height()-50)/dz)+k*50/dx,(width()-50)/dy,(height()-50)/dz);
                    }
                    if(aux[i][j].temBloco){
                        if(k==dimX-1){
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dy) + k*50/dx + 50/(2*dx), j*((height()-50)/dz)+k*50/dx + 50/(2*dx),(width()-50)/dy,(height()-50)/dz);
                        }
                        else{
                            brush.setColor(QColor(aux[i][j].vermelho, aux[i][j].verde, aux[i][j].azul,20));
                            brush.setStyle(Qt::SolidPattern);
                            painter.setBrush(brush);
                            painter.drawEllipse(i*((width()-50)/dy) + k*50/dx + 50/(2*dx), j*((height()-50)/dz)+k*50/dx + 50/(2*dx), (width()-50)/dy,(height()-50)/dz);
                        }
                    }
                }
            }
        }
    }
    brush.setColor(QColor(r,g,b,t));
    painter.setBrush(brush);
    painter.drawRect(500, 20, 50, 50);
}

void Plotter::mousePressEvent(QMouseEvent *event){
    if(plano=="PlanoXY"){
        mouseX = (int) (((1.0*(1.0*(event->x()-1.0*(1.0*dimZ*50)/dx)))/(width()-50))*dx);
        mouseY = (int) (((1.0*(1.0*(event->y()-1.0*(1.0*dimZ*50)/dy)))/(height()-50))*dy);
        putDraw();
    }
    if(plano=="PlanoXZ"){
        mouseX = (int) (((1.0*(1.0*(event->x()-(1.0*dimY*50)/dx)))/(width()-50))*dx);
        mouseY = (int) (((1.0*(1.0*(event->y()-(1.0*dimY*50)/dz)))/(height()-50))*dz);
        putDraw();
    }
    if(plano=="PlanoYZ"){
        mouseX = (int) (((1.0*(1.0*(event->x()-(1.0*dimX*50)/dy)))/(width()-50))*dy);
        mouseY = (int) (((1.0*(1.0*(event->y()-(1.0*dimX*50)/dz)))/(height()-50))*dz);
        putDraw();
    }

}
void Plotter::mouseMoveEvent(QMouseEvent *event){
    if(plano=="PlanoXY"){
        mouseX = (int) (((1.0*(1.0*(event->x()-1.0*(1.0*dimZ*50)/dx)))/(width()-50))*dx);
        mouseY = (int) (((1.0*(1.0*(event->y()-1.0*(1.0*dimZ*50)/dy)))/(height()-50))*dy);
        putDraw();
    }
    if(plano=="PlanoXZ"){
        mouseX = (int) (((1.0*(1.0*(event->x()-(1.0*dimY*50)/dx)))/(width()-50))*dx);
        mouseY = (int) (((1.0*(1.0*(event->y()-(1.0*dimY*50)/dz)))/(height()-50))*dz);
        putDraw();
    }
    if(plano=="PlanoYZ"){
        mouseX = (int) (((1.0*(1.0*(event->x()-(1.0*dimX*50)/dy)))/(width()-50))*dy);
        mouseY = (int) (((1.0*(1.0*(event->y()-(1.0*dimX*50)/dz)))/(height()-50))*dz);
        putDraw();
    }
}

void Plotter::setProfundidade(int profundidadeE){
    if(plano == "PlanoXY")
        dimZ = profundidadeE/100.0*dz;
    if(plano == "PlanoXZ")
        dimY = profundidadeE/100.0*dy;
    if(plano == "PlanoYZ")
        dimX = profundidadeE/100.0*dx;
    repaint();
}

void Plotter::setPlanoXY()
{
    plano = "PlanoXY";
    repaint();
}

void Plotter::setPlanoXZ()
{
    plano = "PlanoXZ";
    repaint();
}

void Plotter::setPlanoYZ()
{
    plano = "PlanoYZ";
    repaint();
}

void Plotter::setTamBoxX(int ent)
{
    tamBoxX = ent;
}

void Plotter::setTamBoxY(int ent)
{
    tamBoxY = ent;
}

void Plotter::setTamBoxZ(int ent)
{
    tamBoxZ = ent;
}

void Plotter::setRaioSphere(int raio)
{
    raioSphere = raio;
}

void Plotter::setRaioEllipeseX(int rX)
{
    tamEllipseX = rX;
}

void Plotter::setRaioEllipeseY(int rY)
{
    tamEllipseY = rY;
}

void Plotter::setRaioEllipeseZ(int rZ)
{
    tamEllipseZ = rZ;
}

void Plotter::setColorR(int red)
{
    r = red;

}

void Plotter::setColorG(int green)
{
    g = green;

}

void Plotter::setColorB(int blue)
{
    b = blue;

}

void Plotter::setPutMetodoVoxel()
{
    metodo = "putVoxel";
}

void Plotter::setPutMetodoBox()
{
    metodo = "putBox";
}

void Plotter::setPutMetodoSphere()
{
    metodo = "putSphere";
}

void Plotter::setPutMetodoEllipse()
{
    metodo = "putEllipse";
}

void Plotter::setPutMetodoCutVoxel()
{
    metodo = "cutVoxel";
}

void Plotter::setPutMetodoCutBox()
{
    metodo = "cutBox";
}

void Plotter::setPutMetodoCutSphere()
{
    metodo = "cutSphere";
}

void Plotter::setPutMetodoCutEllipse()
{
    metodo = "cutEllipse";
}

void Plotter::putDraw()
{
    if(plano=="PlanoXY" ){
        if(metodo == "putVoxel"){
            a = new PutVoxel(mouseX, mouseY, dimZ-1, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putBox"){
            a = new PutBox(dx, dy, dz, mouseX, mouseY, dimZ-1, mouseX+tamBoxX,mouseY+tamBoxY,dimZ+tamBoxZ-1, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putSphere"){
            a = new PutSphere(dx, dy, dz, mouseX, mouseY, dimZ-1, raioSphere, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putEllipse"){
            a = new PutEllipsoid(dx, dy, dz, mouseX, mouseY, dimZ-1, tamEllipseX,  tamEllipseY, tamEllipseZ, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutVoxel"){
            a = new CutVoxel(mouseX, mouseY, dimZ-1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutBox"){
            a = new CutBox(dx, dy, dz, mouseX, mouseY, dimZ-1, mouseX+tamBoxX,mouseY+tamBoxY,dimZ+tamBoxZ-1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutSphere"){
            a = new CutSphere(dx, dy, dz, mouseX, mouseY, dimZ-1, raioSphere);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutEllipse"){
            a = new CutEllipsoid(dx, dy, dz, mouseX, mouseY, dimZ-1, tamEllipseX,  tamEllipseY, tamEllipseZ);
            a->draw(*escultura);
            repaint();
        }
    }
    if(plano=="PlanoXZ" ){
        if(metodo == "putVoxel"){
            a = new PutVoxel(mouseX,dimY-1, mouseY , r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putBox"){
            a = new PutBox(dx, dy, dz, mouseX, dimY-1, mouseY , mouseX+tamBoxX,mouseY+tamBoxY,dimY+tamBoxZ-1, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putSphere"){
            a = new PutSphere(dx, dy, dz, mouseX, dimY-1, mouseY , raioSphere, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putEllipse"){
            a = new PutEllipsoid(dx, dy, dz, mouseX, dimY-1, mouseY , tamEllipseX,  tamEllipseY, tamEllipseZ, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutVoxel"){
            a = new CutVoxel(mouseX, dimY-1, mouseY);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutBox"){
            a = new CutBox(dx, dy, dz, mouseX, dimY-1, mouseY , mouseX+tamBoxX,mouseY+tamBoxY,dimY+tamBoxZ-1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutSphere"){
            a = new CutSphere(dx, dy, dz, mouseX, dimY-1, mouseY , raioSphere);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutEllipse"){
            a = new CutEllipsoid(dx, dy, dz, mouseX, dimY-1, mouseY , tamEllipseX,  tamEllipseY, tamEllipseZ);
            a->draw(*escultura);
            repaint();
        }
    }
    if(plano=="PlanoYZ" ){
        if(metodo == "putVoxel"){
            a = new PutVoxel(dimX-1, mouseX, mouseY, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putBox"){
            a = new PutBox(dx, dy, dz, dimX-1, mouseX, mouseY, mouseX+tamBoxX,mouseY+tamBoxY,dimX+tamBoxZ-1, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putSphere"){
            a = new PutSphere(dx, dy, dz, dimX-1, mouseX, mouseY, raioSphere, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "putEllipse"){
            a = new PutEllipsoid(dx, dy, dz, dimX-1, mouseX, mouseY, tamEllipseX,  tamEllipseY, tamEllipseZ, r, g, b, 1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutVoxel"){
            a = new CutVoxel(dimX-1, mouseX, mouseY);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutBox"){
            a = new CutBox(dx, dy, dz, dimX-1, mouseX, mouseY, mouseX+tamBoxX,mouseY+tamBoxY,dimX+tamBoxZ-1);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutSphere"){
            a = new CutSphere(dx, dy, dz, dimX-1, mouseX, mouseY, raioSphere);
            a->draw(*escultura);
            repaint();
        }
        if(metodo == "cutEllipse"){
            a = new CutEllipsoid(dx, dy, dz, dimX-1, mouseX, mouseY, tamEllipseX,  tamEllipseY, tamEllipseZ);
            a->draw(*escultura);
            repaint();
        }
    }
}






