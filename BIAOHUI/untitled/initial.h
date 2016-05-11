#ifndef INITIAL_H
#define INITIAL_H

#include <QDialog>
#include <QFileDialog>
#include <iostream>
#include <QtGui>
#include "mainwindow.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QString>

namespace Ui {
class initial;
}

class initial : public QDialog
{
    Q_OBJECT

public:
    explicit initial(QWidget *parent = 0);
    ~initial();
signals:
    void setBackPath(QString);
    void setMeetName(QString);
    void setFileName(QString);

private slots:
    void on_pushButtonBrower_clicked();
    void on_pushButtonSure_clicked();

private:
    Ui::initial *ui;

};

#endif // INITIAL_H
