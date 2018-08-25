#include "tank.h"

green_tank::green_tank() : m_coord(QPoint(0, 0)), m_power(0), m_angle(0), rightAimDir(1)
{
}

void green_tank::setPower(int power)
{
    if(power >= 0 && power <= 100 )
        this->m_power = power;
    else
        this->m_power = 100;
}

void green_tank::setAngle(int angle)
{
    if(angle >= 0 && angle <= 359 )
        this->m_angle = angle;
    else
        this->m_angle = 0;
}
