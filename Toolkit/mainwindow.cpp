#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propertieswindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	masterWidget = new GLWidget(0);

	tilesetWindow = new TilesetWindow(ui->widget, masterWidget);

	connect(ui->actionNew_Map, SIGNAL(triggered()), this, SLOT(addTab_Slot()));
	connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab_Slot(int)));
	connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(mapUpdate_Slot(int)));

	// add one map by default
	addTab();
}

MainWindow::~MainWindow()
{
    delete ui;

	Graphics::removeAllTextures();
}

/**
 *  public slots
**/
void MainWindow::addTab_Slot()
{
    addTab();
}

void MainWindow::removeTab_Slot(int id)
{
    removeTab(id);
}

void MainWindow::mapUpdate_Slot(int id)
{
	MapWidget *mapWidget = (MapWidget*)ui->tabWidget->widget(id);
	mapWidget->onActive();
	//
}

/**
 *  public
**/
void MainWindow::addTab()
{
	ui->tabWidget->addTab(new MapWidget(0, masterWidget), QString("New tab"));
	tilesetWindow->updateGL();
}

void MainWindow::removeTab(int id)
{
    ui->tabWidget->removeTab(id);
}
