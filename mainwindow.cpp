#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gradienteditor.h"
#include "gradientviewer.h"
#include "gradient.h"
#include "stop.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    g(new Gradient(QString("paleta_de_prueba"))),
    gv(new GradientViewer(this, g, GradientViewer::HORIZONTAL))
{
    ui->setupUi(this);
//    g->addStop(new Stop(10,QColor(130,54,69)));
//    g->addStop(new Stop(58,QColor(43,180,255)));
    setCentralWidget(gv);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionAsdasdasd_triggered()
{
    GradientEditor *ge = new GradientEditor(new Gradient(*g), this);
    connect(ge,SIGNAL(accepted(Gradient*)),this,SLOT(setGradient(Gradient*)));
    ge->show();
}

void MainWindow::setGradient(Gradient *g)
{
    gv->setGradient(this->g = g);
    g->save("paleta_de_prueba");
}
