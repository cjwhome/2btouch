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
#include <QPushButton>
#include <QThread>
#include <QVector>
#include <QList>
#include <QFile>
#include "defines.h"
#include "showstats.h"
#include "displaygraph.h"
#include "xmldevicereader.h"
#include "twobtechdevice.h"
#include "deviceprofile.h"
#include "serialdataitem.h"
#include "parseddata.h"
#include "filewriter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createDevice();
    void setupSerial();
    void updateDisplay();
    QVector<double> x,y;

    void initFile();            //determine where the file will be saved (usb, locally)
    void createFileName();      //use the device name and date-time.csv (ozone-11416-1553.csv)
    void writeFile();

    bool getStarted_file() const;
    void setStarted_file(bool value);
    QString tempDLine;

signals:
    void validDataReady();

public slots:
    void clearPlotData();
    
private slots:
    void newDataLine(QString dLine);
    bool parseDataLine(QString dLine);
    void displayBigPlot(void);
    void displayStats(void);

private:
	//bool yLessThan(const double &p1, const double &p2);
    Ui::MainWindow *ui;
    SerialThread *s_serialThread;
    ShowStats *showStats;
    QSerialPort *serialPort;
    DisplayGraph *displayGraph;
    QLabel *main_output;
    QLabel *main_label;
    QLabel *main_units_label;
    QLabel *current_time;
    QLabel *current_time_label;
    QLabel *current_date;
    QLCDNumber *mainDisplay;
    QPushButton *graph_button;
    QFile currentFile;


    int data_point;
	double start_time_seconds;
    double main_display_value;
    bool started_file;

    XmlDeviceReader* xmlDeviceReader;
    TwobTechDevice twobTechDevice;
    DeviceProfile deviceProfile;
    ParsedData parsedData;

    QList< QList<SerialDataItem> > allParsedRecordsList;
    FileWriter fileWriter;


};

#endif // MAINWINDOW_H
