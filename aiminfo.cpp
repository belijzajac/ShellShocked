#include "aiminfo.h"
#include "ui_aiminfo.h"

AimInfo::AimInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AimInfo)
{
    ui->setupUi(this);

    // Configure widget appearance
    setStyleSheet("background-color:black;");
    setWindowFlags(Qt::WindowStaysOnTopHint);

    // Labels
    ui->powerLabel->setStyleSheet("QLabel { color : yellow; }");
    ui->angleLabel->setStyleSheet("QLabel { color : yellow; }");
}

AimInfo::~AimInfo()
{
    delete ui;
}

void AimInfo::updatePower(std::unique_ptr<green_tank> &m_tank) const
{
    ui->powerLabel->setText("Power: " + QString::number(m_tank->getPower()));
}

void AimInfo::updateAngle(std::unique_ptr<green_tank> &m_tank) const
{
    if(m_tank->getRightAimDir() == -1)
        ui->angleLabel->setText("Angle: " + QString::number(m_tank->getAngle() + 2 * (90 - m_tank->getAngle())));
    else
        ui->angleLabel->setText("Angle: " + QString::number(m_tank->getAngle()));
}

void AimInfo::closeEvent(QCloseEvent * event)
{
    emit closed();
}
