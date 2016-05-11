#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QApplication::addLibraryPath(".");
    MainWindow w;
    w.setMaximumSize(700,394);
    w.setMinimumSize(700,394);
    w.setWindowTitle(QStringLiteral("信息登记系统"));
    w.show();

    return a.exec();
}
