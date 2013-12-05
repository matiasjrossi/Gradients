#include "stop.h"

#define DEFAULT_COLOR QColor(127,127,127)

Stop::Stop() :
        position(50),
        color(DEFAULT_COLOR)
{
}

Stop::Stop(short position, QColor color) :
        position(position),
        color(color)
{
}

Stop::Stop(Stop &other) :
        QObject(),
        position(other.position),
        color(other.color)
{
}

bool Stop::operator<(const Stop &other) const
{
    return (position<other.getPosition());
}

short Stop::getPosition() const
{
    return this->position;
}

QColor Stop::getColor() const
{
    return this->color;
}

void Stop::deleteStop()
{
    emit deleted(this);
    emit deleted();
}

void Stop::setPosition(int position)
{
    this->position = position;
    emit changed();
    emit changedPosition(this->position);
}

void Stop::setColor(QColor color)
{
    this->color = color;
    emit changed();
}
