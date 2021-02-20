#include "mainwidget.h"
#include "ui_mainwidget.h"

#include "textstreamreader.h"
#include "datastreamwriter.h"

#include <QFileDialog>
#include <QThread>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("Converter");
    // TODO: create and start threads
}

MainWidget::~MainWidget()
{
    // TODO: destroy threads
    delete ui;
}

void MainWidget::on_inputFilePushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    findChild<QLineEdit *>("inputFileLineEdit")->setText(fileName);
}

void MainWidget::on_outputFilePushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    findChild<QLineEdit *>("outputFileLineEdit")->setText(fileName);
}

void MainWidget::on_convertPushButton_clicked()
{
    QString inputFile = findChild<QLineEdit *>("inputFileLineEdit")->text();
    QString outputFile = findChild<QLineEdit *>("outputFileLineEdit")->text();
    TextStreamReader *reader = new TextStreamReader;
    DataStreamWriter *writer = new DataStreamWriter(outputFile);

    // TODO: move reader and writer to required threads

    // TODO: connect reader and writer

    reader->readFromFile(inputFile);
}

void MainWidget::on_inputFileLineEdit_textChanged(const QString &arg1)
{
    TextStreamReader stream;
    //stream.readFromFile("./../qt-09-os-features/data.txt");
   stream.readFromFile(arg1);
}

void MainWidget::on_outputFileLineEdit_textChanged(const QString &arg1)
{
    //
}
