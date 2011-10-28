#include "propertieswindow.h"
#include "ui_propertieswindow.h"

PropertiesWindow::PropertiesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesWindow)
{
    ui->setupUi(this);

	ui->tileset->addItem(tr("../Resources/tiles.png"));
}

PropertiesWindow::~PropertiesWindow()
{
    delete ui;
}

QString PropertiesWindow::getName()
{
	return ui->name->text();
}

QString PropertiesWindow::getTileset()
{
	return ui->tileset->currentText();
}

int PropertiesWindow::getWidth()
{
	return ui->width->value();
}

int PropertiesWindow::getHeight()
{
	return ui->height->value();
}
