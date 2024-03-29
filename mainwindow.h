#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}
class Gradient;
class GradientViewer;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Gradient *g;
    GradientViewer *gv;

private slots:
    void on_actionAsdasdasd_triggered();
    void setGradient(Gradient*);
};

#endif // MAINWINDOW_H
