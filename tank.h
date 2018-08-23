#ifndef TANK_H
#define TANK_H

#include <QPoint>

// Holds tank's specs
class green_tank
{
private:
    QPoint m_coord;
    int m_power, // [0, 100]
        m_angle; // [0, 359]

public:
    green_tank() { m_coord = QPoint(0, 0); m_power = 72; m_angle = 41; }
    ~green_tank() = default;

    void setCoords(const QPoint &coord) { this->m_coord = coord; }
    QPoint getCoords() const { return this->m_coord; }

    void setPower(int power){
        if(power >= 0 && power <= 100 ) this->m_power = power;
        else this->m_power = 0;
    }

    int getPower() const { return this->m_power; }

    void setAngle(int angle){
        if(angle >= 0 && angle <= 359 ) this->m_angle = angle;
        else this->m_angle = 0;
    }

    int getAngle() const { return this->m_angle; }
};

#endif // TANK_H
