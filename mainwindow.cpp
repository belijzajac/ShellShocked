#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_tank(nullptr)
{
    ui->setupUi(this);

    m_tank = std::make_unique<green_tank>();

    // For the event filter to work
    installEventFilter(this);

    // Transparent window
    setParent(nullptr);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    // Labels
    ui->powerLabel->setStyleSheet("QLabel { color : yellow; }");
    ui->angleLabel->setStyleSheet("QLabel { color : yellow; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Set up UI (green border)
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::green, 5));
    painter.drawRect(0, 0, 800, 545);
    painter.drawRect(800, 0, 160, 100);

    // Draw X and Y axis
    painter.setPen(Qt::yellow);
    painter.drawLine(0, m_tank->getCoords().y() - 3, width(), m_tank->getCoords().y() - 3);
    painter.drawLine(m_tank->getCoords().x(), 0, m_tank->getCoords().x(), height());

    // Draw a square
    painter.drawRect(m_tank->getCoords().x() - 10, m_tank->getCoords().y() - 10, 20, 14);

    // To fix the viewpoit from top left corner (0,0) to (m_tank->getCoords().x(), m_tank->getCoords().y())
    QMatrix matrix;
    matrix.translate(m_tank->getCoords().x(), m_tank->getCoords().y()); // (0,0) to the middle of the tank square
    matrix.scale(1, -1);                                                // scale Y axis by -1 factor (invert Y axis from upside down)

    painter.setMatrix(matrix);

    // draw parabola
    painter.setPen(QPen(Qt::magenta, 1));
    drawParabola(painter);
}

void MainWindow::drawParabola(QPainter &painter)
{
    float x_min = 10.8;
    float x_max = 2 * getDistance();
    float step = 0.5;

    QVector<QPointF> points;
    float x = x_min;
    while(x < x_max){
        float y = heightPerX(x); // f(x)
        points.push_back(QPointF(x, y));
        x += step;
    }
    painter.drawLines(points);
}

// Filters mouse and keyboard events
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // Mouse button click event
    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        int x = mouseEvent->pos().x();
        int y = mouseEvent->pos().y();
        m_tank->setCoords(QPoint(x, y));

        this->update(); // redraws QPainter on every click!
    }

    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        // Descrease power
        if(keyEvent->key() == Qt::Key_4){ // [4] was pressed
            m_tank->setPower(m_tank->getPower() - 1);

            updatePower();
            this->update();
        }
        // Increase power
        if(keyEvent->key() == Qt::Key_6){ // [6] was pressed
            m_tank->setPower(m_tank->getPower() + 1);

            updatePower();
            this->update();
        }
        // Descrease angle
        if(keyEvent->key() == Qt::Key_2){ // [2] was pressed
            m_tank->setAngle(m_tank->getAngle() - 1);

            updateAngle();
            this->update();
        }
        // Increase angle
        if(keyEvent->key() == Qt::Key_8){ // [8] was pressed
            m_tank->setAngle(m_tank->getAngle() + 1);

            updateAngle();
            this->update();
        }
    }
    return false;
}

float MainWindow::getHeight() const
{
    int gravity = 20;
    return 9.80 * ( m_tank->getPower() * m_tank->getPower() * sin(m_tank->getAngle()) * sin(m_tank->getAngle()) ) / ( 2 * gravity );
}

float MainWindow::getDistance() const
{
    return 1.38 * getHeight() / tan(m_tank->getAngle());
}

float MainWindow::heightPerX(int x) const
{
    float height = getHeight();
    float distance = getDistance();

    return 4 * (- height / (distance * distance) * (x - distance) * (x - distance) + height);
}

void MainWindow::updatePower() const
{
    ui->powerLabel->setText("Power: " + QString::number(m_tank->getPower()));
}

void MainWindow::updateAngle() const
{
    ui->angleLabel->setText("Angle: " + QString::number(m_tank->getAngle()));
}