#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

int tab = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myWidget = new GLWidget(0);

    connect(ui->actionNew_Map, SIGNAL(triggered()), this, SLOT(addTab_Slot()));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab_Slot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTab_Slot()
{
    addTab();
}

void MainWindow::removeTab_Slot(int id)
{
    removeTab(id);
}

void MainWindow::addTab()
{
    ui->tabWidget->addTab(new GLWidget(0, myWidget), QString("New tab %1").arg(tab));
    tab++;
}

void MainWindow::removeTab(int id)
{
    ui->tabWidget->removeTab(id);
}
