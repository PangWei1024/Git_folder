#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "textclass.h"

#include <QTime>
#include "thread_text.h"
#include <qwt_plot.h>

 #include <qwt_plot_magnifier.h>
 #include <qwt_plot_panner.h>
 #include <qwt_legend.h>
#include <qwt_point_data.h>
#include <qmath.h>
#include <QVector>
#include "qwaitcondition.h"
#include <QtGlobal>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "begin";
   // connect(MainWindow::on_pushButton_clicked(),&MainWindow::on_lineEdit_editingFinished(),0);
    QObject::connect(ui->pushButton,&QPushButton::clicked,&QApplication::quit);

    textclass aqw;
    aqw.getvalue2();

    QTimer *timer = new QTimer(this);
        timer->start(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::print_text);
    thread_text* thread_t = new thread_text;
    thread_t->start();
    QwtPlotCurve* curve1 = new QwtPlotCurve("Curve 1");


//    QwtPlot plot(QwtText("CppQwtExample1"));
//     plot.resize(640,400);
//     //设置坐标轴的名称
     ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "x->");
     ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "y->");
//     //设置坐标轴的范围
//     plot.setAxisScale(QwtPlot::xBottom, 0.0, 2.0 * M_PI);
//     plot.setAxisScale(QwtPlot::yLeft, -1.0, 1.0);
//     //设置右边标注
     ui->qwtPlot->insertLegend(new QwtLegend(), QwtPlot::RightLegend);

//     //使用滚轮放大/缩小
     (void) new QwtPlotMagnifier( ui->qwtPlot->canvas() );

//     //使用鼠标左键平移
     (void) new QwtPlotPanner( ui->qwtPlot->canvas() );

//     //构造曲线数据
//     QwtPointArrayData * const data = new QwtPointArrayData(xs, ys);
//     QwtPlotCurve curve("Sine");
//     curve.setData(data);//设置数据
//     curve.setStyle(QwtPlotCurve::Lines);//直线形式
//     curve.setCurveAttribute(QwtPlotCurve::Fitted, true);//是曲线更光滑
//     curve.setPen(QPen(Qt::blue));//设置画笔

//     curve.attach(&plot);//把曲线附加到plot上

//     plot.show();

    //数据x,y值保存

    QVector<QPointF> vector;
    for(int i =0;i<150;i++){
        QPointF point;
        point.setX(i);
       int y = 20*sin(i*M_PI/10) + 50;
        point.setY(y);
        vector.append(point);
    }
    //构造曲线数据
    QwtPointSeriesData* series = new QwtPointSeriesData(vector);
    //create plot item
   // QwtPlotCurve* curve1 = new QwtPlotCurve("Curve 1");
         curve1->setStyle(QwtPlotCurve::Lines);//直线形式
         curve1->setCurveAttribute(QwtPlotCurve::Fitted, true);//是曲线更光滑
    curve1->setPen(QPen(Qt::blue));//设置画笔
    //设置数据
    curve1->setData(series);
    //把曲线附加到qwtPlot上
    curve1->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    ui->qwtPlot->show();


    connect(&updateTimer,SIGNAL(timeout()),this,SLOT(updatedataSlot()));
    updateTimer.start(0);



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::print_text()
{
    qDebug()<< "function debug";
}
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "123";
    ui->lineEdit->setText("printing");
}

void MainWindow::on_lineEdit_editingFinished()
{
    qDebug() << "456";
}

void MainWindow::on_pushButton_2_clicked()
{
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for(int i=0; i<10; i++)
        {
            int test =qrand()%10;
            qDebug()<<test;
        }
}
