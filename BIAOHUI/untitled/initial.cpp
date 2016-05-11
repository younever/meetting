#include "initial.h"
#include "ui_initial.h"

initial::initial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initial)
{

    ui->setupUi(this);
}

initial::~initial()
{
    delete ui;
}

void initial::on_pushButtonBrower_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,QStringLiteral("选择背景图片"),".",QStringLiteral("Image Files(*.jpg *.png)"));
//    qDebug()<<path;
    ui->lineEditBackPath->setText(path);

}

void initial::on_pushButtonSure_clicked()
{

    if(ui->lineEditBackPath->text().isEmpty()||ui->lineEditFileName->text().isEmpty()||ui->lineEditMeetName->text().isEmpty())
//    if(ui->lineEditFileName->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox.setText(QStringLiteral("请输入完整预设信息"));
        msgBox.exec();
     }
    else
    {
        if(!ui->xls->isChecked()&&!ui->xlsx->isChecked())
        {
            QMessageBox msgBox;
            msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox.setText(QStringLiteral("请选择保存的数据类型"));
            msgBox.exec();
        }
        else
        {
            QString fileType;
            if(ui->xls->isChecked()) fileType = ".xls";
            if(ui->xlsx->isChecked()) fileType = ".xlsx";

            emit setBackPath(ui->lineEditBackPath->text());
            emit setMeetName(ui->lineEditMeetName->text());
            emit setFileName(QDir::toNativeSeparators("C:\\"+ui->lineEditFileName->text()+fileType));
            this->hide();

        }

   }

}
