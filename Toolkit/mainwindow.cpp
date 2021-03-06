#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propertieswindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// set up the master widget
	masterWidget = new GLWidget(0);

	// set up the tileset window
	tilesetWindow = new TilesetWindow(ui->widget, masterWidget);

	// connext signals to slots
	connect(ui->actionNew_Map, SIGNAL(triggered()), this, SLOT(addTab_Slot()));
	connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab_Slot(int)));
	connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(mapUpdate_Slot(int)));
	connect(ui->actionOpen_Map, SIGNAL(triggered()), this, SLOT(openMap_Slot()));
	connect(ui->actionSave_Map, SIGNAL(triggered()), this, SLOT(saveMap_Slot()));
	connect(ui->actionProperties, SIGNAL(triggered()), this, SLOT(showProperties_Slot()));
}

MainWindow::~MainWindow()
{
	// delete the ui
    delete ui;
	// remove the masterWidget
	delete masterWidget;
	// delete the tileset window
	delete tilesetWindow;
	// remove all textures
	Graphics::removeAllTextures();
}

/**
 *  public slots
**/
void MainWindow::addTab_Slot()
{
	// call addTab
    addTab();
}

void MainWindow::removeTab_Slot(int id)
{
	// call removeTab
    removeTab(id);
}

void MainWindow::mapUpdate_Slot(int id)
{
	// grab the tab at the index
	MapWidget *mapWidget = (MapWidget*)ui->tabWidget->widget(id);

	// if the widget exists then call onActive
	if (mapWidget != NULL)
		mapWidget->onActive();
}

void MainWindow::mapChangeSelection_Slot(Rectangle newRectangle)
{
	// set the selection on the tilsetWindow to the map selection
	tilesetWindow->setSelection(newRectangle);
}

void MainWindow::openMap_Slot()
{
	// open the map file with QFileDialog returns qstring of file path
	QString mapFile = QFileDialog::getOpenFileName(0, tr("Open map"), tr("../Resources"), tr("Map (*.map)"));

	// if it's not empty or null ...
	if (!mapFile.isNull() && !mapFile.isEmpty())
	{
		// create a new tab and load the map
		MapWidget *mapWidget = addTab(false);

		// load the map in the current tab !
		mapWidget->loadMap(mapFile);

		// set the tab's name to the current map name
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tr(mapWidget->getMap()->getName().c_str()));
	}
}

void MainWindow::saveMap_Slot()
{
	// saving map with QFileDialog and returns qstring of file path
	QString mapFile = QFileDialog::getSaveFileName(0, tr("Save map"), tr("../Resources"), tr("Map (*.map)"));

	// grab the widget of the current tab up
	MapWidget *mapWidget = (MapWidget*)ui->tabWidget->currentWidget();

	// save the map :)
	mapWidget->saveMap(mapFile);
}

void MainWindow::showProperties_Slot()
{
	// get current tab
	MapWidget *mapWidget = (MapWidget*) ui->tabWidget->currentWidget();

	// show the properties window for that map tab
	mapWidget->showProperties();
}

void MainWindow::propertiesAccepted_Slot()
{
	// get the current widget
	MapWidget *mapWidget = (MapWidget*) ui->tabWidget->currentWidget();

	// get the tab name based on new name of map
	ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tr(mapWidget->getMap()->getName().c_str()));
}

/**
 *  public
**/
MapWidget *MainWindow::addTab(bool showProperties)
{
	// create a new mapWidget
	MapWidget *mapWidget = new MapWidget(0, masterWidget);
	// add the signal slot connection to change selection (could be done with static slots but pointless
	connect(mapWidget, SIGNAL(changedSelection(Rectangle)), this, SLOT(mapChangeSelection_Slot(Rectangle)));
	// signal slot for changing tab (could redo this as well?)
	connect(mapWidget, SIGNAL(propertiesAccepted()), this, SLOT(propertiesAccepted_Slot()));
	// create the new tab and switch the current index to this tab
	ui->tabWidget->setCurrentIndex(ui->tabWidget->addTab(mapWidget, QString("New tab")));
	// update the tileset window
	// TODO: may need to change to grab the map sprite instead
	tilesetWindow->updateGL();
	// if we're creating a new tab we will show the properties
	if (showProperties) mapWidget->showProperties();

	return mapWidget;
}

void MainWindow::removeTab(int id)
{
	// remove the tab widget at the tab place
	ui->tabWidget->removeTab(id);
}
