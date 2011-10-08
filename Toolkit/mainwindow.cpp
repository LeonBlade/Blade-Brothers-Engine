#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propertieswindow.h"

#include <QFileDialog>

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
	connect(ui->actionOpen_Map, SIGNAL(triggered()), this, SLOT(openMap_Slot()));
	connect(ui->actionSave_Map, SIGNAL(triggered()), this, SLOT(saveMap_Slot()));

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
}

void MainWindow::mapChangeSelection_Slot(Rectangle newRectangle)
{
	tilesetWindow->setSelection(newRectangle);
}

void MainWindow::openMap_Slot()
{
	QString mapFile = QFileDialog::getOpenFileName(0, tr("Open map"), tr("../Resources"), tr("Map (*.map)"));

	if (!mapFile.isNull() && !mapFile.isEmpty())
	{
		// TODO: either override or pass in option to open map with addTab
		MapWidget *mapWidget = new MapWidget(0, masterWidget);
		Map *map = mapWidget->getMap();
		if (map)
		{
			map->onLoad(mapFile.toStdString().c_str());
			connect(mapWidget, SIGNAL(changedSelection(Rectangle)), this, SLOT(mapChangeSelection_Slot(Rectangle)));
			ui->tabWidget->addTab(mapWidget, QString("MAP NAME"));
			tilesetWindow->updateGL();
		}
	}
}

void MainWindow::saveMap_Slot()
{
	QString mapFile = QFileDialog::getSaveFileName(0, tr("Save map"), tr("../Resources"), tr("Map (*.map)"));
	MapWidget *mapWidget = (MapWidget*)ui->tabWidget->currentWidget();
	mapWidget->getMap()->onSave(mapFile.toStdString().c_str());
}

/**
 *  public
**/
void MainWindow::addTab()
{
	MapWidget *mapWidget = new MapWidget(0, masterWidget);
	connect(mapWidget, SIGNAL(changedSelection(Rectangle)), this, SLOT(mapChangeSelection_Slot(Rectangle)));
	ui->tabWidget->addTab(mapWidget, QString("New tab"));
	tilesetWindow->updateGL();
}

void MainWindow::removeTab(int id)
{
    ui->tabWidget->removeTab(id);
}
