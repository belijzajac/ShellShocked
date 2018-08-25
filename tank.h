#ifndef TANK_H
#define TANK_H

#include <QPoint>

// Holds tank's specs
class green_tank
{
private:
    QPoint m_coord;
    int m_power,     // [0, 100]
        m_angle;     // [0, 359]
    int rightAimDir; // 1 or -1 (right or left)

public:
    green_tank();
    ~green_tank() = default;

    void setCoords(const QPoint &coord) { this->m_coord = coord; }
    QPoint getCoords() const { return this->m_coord; }

    void setPower(int power);
    int getPower() const { return this->m_power; }

    void setAngle(int angle);
    int getAngle() const { return this->m_angle; }

    void changeAimDir(){ (rightAimDir == 1)? rightAimDir = -1 : rightAimDir = 1; }
    int getRightAimDir() const { return  this->rightAimDir; }
};

#endif // TANK_H
