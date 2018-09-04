#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qwt_plot_curve.h>
#include <QMainWindow>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QwtPlotCurve* curve1;
    QTimer updateTimer;
private slots:
    void on_pushButton_2_clicked();

signals:
    void on_pushButton_clicked();
public slots:
    void on_lineEdit_editingFinished();
    void print_text();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
