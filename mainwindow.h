#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "serialthread.h"
#include <QtSerialPort/QSerialPort>
#include <QDateTime>
#include <QMessageBox>
#include <QLabel>
#include <QtGui>
#include <QThread>
//#include <QWSServer>
#include <QVector>
#include "defines.h"
#include "qcustomplot.h"
#include "showstats.h"
#include "defines.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupSerial();
    QVector<double> x,y;
	
signals:
	void readyToPlot();
private slots:
    void newDataLine(QString dLine);
    void parseDataLine(QString dLine);
	void rePlot(void);

private:
	//bool yLessThan(const double &p1, const double &p2);
    Ui::MainWindow *ui;
    SerialThread *s_serialThread;
    ShowStats *showStats;
    QSerialPort *serialPort;
    QLabel *ozone_output;
    QLabel *ozone_label;
    QLabel *ozone_units_label;
    QLabel *temperature_output;
    QLabel *temperature_label;
    QLabel *temperature_units_label;
    QLabel *pressure_output;
    QLabel *pressure_label;
    QLabel *pressure_units_label;
    QLabel *current_time;
    QLabel *current_time_label;
	QLCDNumber *ozoneDisplay;

    double current_ozone;
    double current_temp;
    double current_press;
    double current_pdv;
    int data_point;
	double start_time_seconds;
	

    //QDateTime tempDateTime;
    QCustomPlot *customPlot;
    //int y;
    //int x;      //graphing test



};

#endif // MAINWINDOW_H
