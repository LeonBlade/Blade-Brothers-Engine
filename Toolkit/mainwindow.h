#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "mapwidget.h"
#include "tilesetwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTab_Slot();
    void removeTab_Slot(int id);
	void mapUpdate_Slot(int id);

public:
    void addTab();
    void removeTab(int id);

private:
    Ui::MainWindow *ui;
	GLWidget *masterWidget;
	TilesetWindow *tilesetWindow;
};

#endif // MAINWINDOW_H
