#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <excelengine.h>
#include <QMainWindow>
#include "initial.h"
#include <QtGui>
#include <QAxObject>
#include <excelengine.h>
#include "iostream"
#include <QPalette>
#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include <QDir>
#include <QString>
#include <QFileDialog>
#include <QTextCodec>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetBackground(QString picPath);
    void ExcelInitial();

     QString MeetName;
     QString BackPath;
     QString FileName;
     ExcelEngine excel; //创建excl对象
private slots:
    void on_pushButtonAdd_clicked();
//    void on_pushButtonFinish_clicked();

    void receiveBackPath(QString data);
    void receiveFileName(QString data);
    void receiveMeetName(QString data);



    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    bool excelFlag;
    QString sxlsfile;
//    ExcelEngine excel; //创建excl对象
   // initial initialDia;


};

#endif // MAINWINDOW_H
