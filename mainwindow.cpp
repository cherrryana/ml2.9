#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int i = 0; i < k; i++)
        points[i] -> draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *point = nullptr;
    if (k > 9) return;
    int f = 0;
    QPoint qpoint;
    qpoint.setX(event -> x());
    qpoint.setY(event -> y());

    for (int i = 0; i < k; i++)
    {
        if (points[i] -> distance2(qpoint) < 4)
        {
            points[i]->setX(qpoint.x());
            points[i]->setY(qpoint.y());
            f = 1;
        }
    }

    if (f == 0)
    {
       point = new Point(event -> x(), event -> y());
       points[k] = point;
       k++;
    }
    repaint();
}
