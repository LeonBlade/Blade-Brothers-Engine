#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWidget = new GLWidget(0);
    tsWidget = new GLWidget(0, myWidget);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);

    ui->tabWidget->addTab(myWidget, tr("New map"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
