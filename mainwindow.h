#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tank.h"
#include "aiminfo.h"

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
    ~MainWindow() override;

    void paintEvent(QPaintEvent *event) override;
    void drawParabola(QPainter &painter);

    bool eventFilter(QObject *obj, QEvent *event) override;

    float getHeight() const;
    float getDistance() const;
    float heightPerX(int x) const;
    float angleToRadians(float degrees) const;

public slots:
    void closeApp();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<green_tank> m_tank;
    std::unique_ptr<AimInfo> m_aiminfo;
};

#endif // MAINWINDOW_H
