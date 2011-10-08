#ifndef PROPERTIESWINDOW_H
#define PROPERTIESWINDOW_H

#include <QDialog>

namespace Ui {
    class PropertiesWindow;
}

class PropertiesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PropertiesWindow(QWidget *parent = 0);
    ~PropertiesWindow();

	QString getName();
	QString getTileset();
	int getWidth();
	int getHeight();

private:
    Ui::PropertiesWindow *ui;
};

#endif // PROPERTIESWINDOW_H
