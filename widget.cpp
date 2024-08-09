#include "widget.h"
#include "./ui_widget.h"
#include "txt2ply.h"

#include <QProcess>

#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QString>

#include<QMetaType>

using namespace std;

QString inputPath;
QString outputPath;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::a)
{

    ui->setupUi(this);

    fileProcessor = new Txt2Ply();

    // 谁发出信号，发出什么信号，谁处理信号，怎么处理
    // 连接信号和槽
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Widget::startProcessing);
    connect(fileProcessor, &Txt2Ply::processingFinished, this, &Widget::finishProcessing);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //文件对话框
    inputPath=QFileDialog::getOpenFileName(this,"OPEN","../","TXT(*.txt)");//设置文件路径 文件格式F
    if(inputPath.isEmpty()==false){//路径正确
        //创建文件对象 并且关联起来
        QFile file(inputPath);
        bool isok=file.open(QIODevice::ReadOnly);//利用只读模式打开文件
        if(isok){//打开成功
            ui->inputFilePath->setText(inputPath);
        }
        file.close();
    }
}

void Widget::on_pushButton_3_clicked()
{
    //文件对话框
    outputPath=QFileDialog::getSaveFileName(this,"SAVE","../","PLY(*.ply)");//设置保存文件的路径 文件格式
    if(outputPath.isEmpty()==false){//路径正确
        //创建文件对象 并且关联起来
        QFile file(outputPath);
        bool isok=file.open(QIODevice::WriteOnly);//利用只读模式打开文件
        if(isok){//打开成功
            ui->outputFilePath->setText(outputPath);//获取编辑区的内容
        }
        file.close();//关闭文件
    }
}

void Widget::startProcessing(){
    ui->pushButton_4->setText("Processing...");
    ui->pushButton_4->setEnabled(false);

    QCoreApplication::processEvents();
    fileProcessor->translate(inputPath,outputPath);
}

void Widget::finishProcessing(){
    qDebug()<<"finished";
    ui->pushButton_4->setText("Finished");
    ui->pushButton_4->setEnabled(true);
}
