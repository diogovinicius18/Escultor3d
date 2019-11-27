#include "cor.h"
#include <QPainter>
#include <QBrush>
#include <QPen>



Cor::Cor(QWidget *parent) : QWidget(parent)
{
    rC=0;
    gC=0;
    bC=0;
}

void Cor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(rC,gC,bC));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());
}

void Cor::CorR(int re)
{
    rC = re;
    repaint();
}

void Cor::CorG(int ge)
{
    gC = ge;
    repaint();
}

void Cor::CorB(int be)
{
    bC = be;
    repaint();
}
