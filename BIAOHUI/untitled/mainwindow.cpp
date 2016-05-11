#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    //excel.setProperty("DisplayAlerts", false);
    excelFlag =0;
    initial *initialDia = new initial();
    initialDia->setWindowTitle(QStringLiteral("信息系统登记预设"));
    initialDia->setMaximumSize(411,182);
    initialDia->setMinimumSize(411,182);
    initialDia->setWindowFlags(Qt::WindowStaysOnTopHint);
    initialDia->show();
    connect(initialDia,SIGNAL(setBackPath(QString)),this,SLOT(receiveBackPath(QString)));
    connect(initialDia,SIGNAL(setFileName(QString)),this,SLOT(receiveFileName(QString)));
    connect(initialDia,SIGNAL(setMeetName(QString)),this,SLOT(receiveMeetName(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::SetBackground(QString picPath)
{
    QPixmap pixmap(picPath);//这个图片路径写自己的.
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);


}

void MainWindow::ExcelInitial()
{
    //ExcelEngine excel; //创建excl对象
    //excel.Open(excelPath,1,false); //打开指定的xls文件的指定sheet，且指定是否可见

//    excel.setProperty("DisplayAlerts", 0);
//    excel.Open(QDir::toNativeSeparators(sxlsfile),1,false); //打开指定的xls文件的指定sheet，且指定是否可见
    excel.Open(sxlsfile,1,false);
    excel.SetCellData(1,1,QStringLiteral("姓名"));
    excel.SetCellData(1,2,QStringLiteral("性别"));
    excel.SetCellData(1,3,QStringLiteral("单位"));
    excel.SetCellData(1,4,QStringLiteral("科室"));
    excel.SetCellData(1,5,QStringLiteral("职称"));
    excel.SetCellData(1,6,QStringLiteral("职务"));
    excel.SetCellData(1,7,QStringLiteral("手机"));
    excel.SetCellData(1,8,QStringLiteral("邮箱"));
    excel.Close();


}

void MainWindow::on_pushButtonAdd_clicked()
{
    QVariant sexState,unit_,department,techtitle,admintitle,phone,email,name;

    if (ui->radioButtonMen->isChecked()) sexState = QStringLiteral("男");
    if(ui->radioButtonWomen->isChecked()) sexState = QStringLiteral("女");
    unit_ = ui->lineEditUnit->text();
    department = ui->lineEditDeparment->text();
    techtitle = ui->lineEditTechTitle->text();
    admintitle = ui->lineEditAdminTitle->text();
    phone = ui->lineEditPhone->text();
    email = ui->lineEditEmail->text();
    name = ui->lineEditName->text();

    if(name==""||phone=="")
    {
        QMessageBox msgBox;
        msgBox.setText(QStringLiteral("姓名或手机号码不能为空"));
        msgBox.exec();
    }
    else
    {

        if(!excelFlag)
        {
            ExcelInitial();
            excelFlag = 1;
        }
    //    ExcelEngine excel; //创建excl对象QObject::tr("C:\\12345.xlsx")
        //excel.Open(QDir::toNativeSeparators(sxlsfile),1,false); //打开指定的xls文件的指定sheet，且指定是否可见
        excel.Open(sxlsfile,1,false);
        uint aRow = excel.GetRowCount();
        excel.SetCellData(aRow+1,1,name);
        excel.SetCellData(aRow+1,2,sexState);
        excel.SetCellData(aRow+1,3,unit_);
        excel.SetCellData(aRow+1,4,department);
        excel.SetCellData(aRow+1,5,techtitle);
        excel.SetCellData(aRow+1,6,admintitle);
        excel.SetCellData(aRow+1,7,"'"+phone.toString());
        excel.SetCellData(aRow+1,8,email);
        excel.Close();
//        excel.Save();

        ui->lineEditName->clear();
        ui->lineEditUnit->clear();
        ui->radioButtonMen->setChecked(true);
        ui->radioButtonWomen->setChecked(true);
        ui->lineEditDeparment->clear();
        ui->lineEditAdminTitle->clear();
        ui->lineEditTechTitle->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
        QMessageBox msgBox;
        msgBox.setText(QStringLiteral("已添加成功"));
        msgBox.setInformativeText(name.toString());
        msgBox.setDetailedText(name.toString()+"  "+sexState.toString()+"\n"+unit_.toString()+"\n"+department.toString()+
                    "\n"+techtitle.toString()+"\n"+admintitle.toString()+"\n"+phone.toString()+"\n"+email.toString());
        msgBox.exec();
    }


}


void MainWindow::receiveBackPath(QString data)
{
//    qDebug()<<data;
    SetBackground(data);
}
void MainWindow::receiveFileName(QString data)
{
    //"C:\\Users\\Administrator.TX0VLQ8YTO59LX1\\Documents\\Book100.xls"
    sxlsfile =data;
   // sxlsfile = QFileDialog::getSaveFileName(NULL,"Save File",".","Excel File(*.xls)");
    qDebug()<<sxlsfile;

}
void MainWindow::receiveMeetName(QString data)
{
    ui->labelTitle->setText(data);

}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEditName->clear();
    ui->lineEditUnit->clear();
    ui->radioButtonMen->setChecked(true);
    ui->radioButtonWomen->setChecked(true);
    ui->lineEditDeparment->clear();
    ui->lineEditAdminTitle->clear();
    ui->lineEditTechTitle->clear();
    ui->lineEditEmail->clear();
    ui->lineEditPhone->clear();
    QMessageBox msgBox;
    msgBox.setText(QStringLiteral("数据已经清除"));
    msgBox.exec();
}


