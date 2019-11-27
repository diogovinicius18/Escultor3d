#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionSalvar, SIGNAL(triggered(bool)), ui->widget, SLOT(salvarArquivo));
    connect(ui->actionPutVoxel, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoVoxel()));
    connect(ui->actionPutBox, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoBox()));
    connect(ui->actionPutSphere, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoSphere()));
    connect(ui->actionPutEllipse, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoEllipse()));
    connect(ui->actionCutVoxel, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoCoxel()));
    connect(ui->actionCutBox, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoCutBox()));
    connect(ui->actionCutSphere, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoCutSphere()));
    connect(ui->actionCutEllipsoid, SIGNAL(triggered(bool)), ui->widget, SLOT(setPutMetodoCutEllipse()));
    connect(ui->Profundidade, SIGNAL(valueChanged(int)), ui->widget, SLOT(setProfundidade(int)));
    connect(ui->PlanoXY, SIGNAL(clicked()), ui->widget, SLOT(setPlanoXY()));
    connect(ui->PlanoXZ, SIGNAL(clicked()), ui->widget, SLOT(setPlanoXZ()));
    connect(ui->PlanoYZ, SIGNAL(clicked()), ui->widget, SLOT(setPlanoYZ()));
    connect(ui->SliderRED, SIGNAL(valueChanged(int)), ui->widgetCor, SLOT(CorR(int)));
    connect(ui->SliderGreen, SIGNAL(valueChanged(int)), ui->widgetCor, SLOT(CorG(int)));
    connect(ui->SliderBlue, SIGNAL(valueChanged(int)), ui->widgetCor, SLOT(CorB(int)));
    connect(ui->SliderRED, SIGNAL(valueChanged(int)), ui->widget, SLOT(setColorR(int)));
    connect(ui->SliderGreen, SIGNAL(valueChanged(int)), ui->widget, SLOT(setColorG(int)));
    connect(ui->SliderBlue, SIGNAL(valueChanged(int)), ui->widget, SLOT(setColorB(int)));
    connect(ui->SliderBoxDimX, SIGNAL(valueChanged(int)), ui->widget, SLOT(setTamBoxX(int)));
    connect(ui->SliderBoxDimY, SIGNAL(valueChanged(int)), ui->widget, SLOT(setTamBoxY(int)));
    connect(ui->SliderBoxDimZ, SIGNAL(valueChanged(int)), ui->widget, SLOT(setTamBoxZ(int)));
    connect(ui->SliderRaio, SIGNAL(valueChanged(int)), ui->widget, SLOT(setRaioSphere(int)));
    connect(ui->SliderEllipseDimX, SIGNAL(valueChanged(int)), ui->widget, SLOT((setRaioEllipseX(int))));
    connect(ui->SliderEllipseDimY, SIGNAL(valueChanged(int)), ui->widget, SLOT((setRaioEllipseY(int))));
    connect(ui->SliderEllipseDimZ, SIGNAL(valueChanged(int)), ui->widget, SLOT((setRaioEllipseZ(int))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::novaDimensao()
{
    Dialog att;
}
