#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tank.h"

#include <QMainWindow>
#include <QPainter>
#include <memory>

const float PI = 3.1415;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void drawParabola(QPainter &painter);

    bool eventFilter(QObject *obj, QEvent *event);

    float getHeight() const;
    float getDistance() const;
    float heightPerX(int x) const;
    float angleToRadians(float degrees) const;

    void updatePower() const;
    void updateAngle() const;

private:
    Ui::MainWindow *ui;

    std::unique_ptr<green_tank> m_tank;
};

#endif // MAINWINDOW_H
