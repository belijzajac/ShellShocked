#ifndef AIMINFO_H
#define AIMINFO_H

#include "tank.h"

#include <QWidget>
#include <memory>

namespace Ui {
class AimInfo;
}

class AimInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AimInfo(QWidget *parent = nullptr);
    ~AimInfo() override;

    // passing by reference to not take ownership of m_tank
    void updatePower(std::unique_ptr<green_tank> &m_tank) const;
    void updateAngle(std::unique_ptr<green_tank> &m_tank) const;

    void closeEvent(QCloseEvent * event) override;

signals:
    void closed();

private:
    Ui::AimInfo *ui;
};

#endif // AIMINFO_H
