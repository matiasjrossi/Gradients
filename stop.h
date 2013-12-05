#ifndef STOP_H
#define STOP_H

#include <QObject>
#include <QColor>

class Stop : public QObject
{
    Q_OBJECT
public:
    Stop();
    Stop(short,QColor);
    Stop(Stop &other);
    bool operator<(const Stop &other) const;
    short getPosition() const;
    QColor getColor() const;
public slots:
    void deleteStop();
    void setPosition(int);
    void setColor(QColor);
signals:
    void deleted(Stop*);
    void deleted();
    void changed();
    void changedPosition(int);
private:
    short position;
    QColor color;
};

#endif // STOP_H
