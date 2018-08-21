#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Transparent window
    setParent(nullptr);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    // Labels
    ui->powerLabel->setStyleSheet("QLabel { color : yellow; }");
    ui->angleLabel->setStyleSheet("QLabel { color : yellow; }");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Set up UI (green border)
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::green, 5));
    painter.drawRect(0, 0, 800, 545);
    painter.drawRect(800, 0, 160, 100);

    // do stuff...
}

MainWindow::~MainWindow()
{
    delete ui;
}
