#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include "arrowdelegate.h"

#include <QMainWindow>
#include <QTextStream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadData(const QString &fn);

    void buildTable();

private:
    Ui::MainWindow *ui;

    QString datafile;
    int m_width;

    Model *csv;
    QStringList data;

};

#endif // MAINWINDOW_H
