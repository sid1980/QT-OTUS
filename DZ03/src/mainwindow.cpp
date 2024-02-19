#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "model.h"

#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , datafile {"gold.csv"}
    , m_width {700}
    , csv {nullptr}
{
    ui->setupUi(this);
    this->setMinimumWidth(m_width);

    csv = new Model(this);
    ui->tableView->setModel(csv);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);


    ui->tableView->setItemDelegateForColumn(1, new ArrowDelegate(ui->tableView));
    ui->tableView->setItemDelegateForColumn(2, new ArrowDelegate(ui->tableView));

    loadData(datafile);

    buildTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadData(const QString &fn)
{
    QFile file(fn);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in (&file);

        while( !in.atEnd() ) {
            data.append(in.readLine());
        }

        file.close();
    }
}

void MainWindow::buildTable()
{
    for (int lineIdx{0}; lineIdx < data.size(); lineIdx++)
    {
        QStringList line = data.at(lineIdx).split(",");

        if (lineIdx == 0) {
            csv->setHorizontalHeaderLabels(line);
            csv->setColumnCount(line.size());
            continue;
        }
        else
        {
            for( int i{0}; i < line.size(); ++i )
            {
                QStandardItem *item = new QStandardItem(line.at(i));
                csv->setItem(lineIdx - 1, i, item);
            }
        }
    }
}
