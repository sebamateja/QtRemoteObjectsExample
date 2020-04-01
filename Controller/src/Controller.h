#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QTimer>
#include <rep_Controller_source.h>

class Controller : public ControllerSimpleSource
{
    Q_OBJECT
public:
    Controller(QObject *parent = nullptr);
    ~Controller();

    bool currentState() const;
    void setCurrentState(bool currentState);

    virtual void testFunction(QString string);

public Q_SLOTS:
    void timeout_slot();

private:
    bool m_currentState = false;
    QTimer *stateChangeTimer;
};

#endif // CONTROLLER_H
