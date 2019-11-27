#ifndef COR_H
#define COR_H


#include <QWidget>
#include "plotter.h"

class Cor : public QWidget
{
    Q_OBJECT
protected:
    int rC,gC,bC;

public:
    explicit Cor(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void CorR(int re);
    void CorG(int ge);
    void CorB(int be);
};

#endif // COR_H
