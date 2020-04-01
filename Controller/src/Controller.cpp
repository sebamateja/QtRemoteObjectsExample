#include "Controller.h"

Controller::Controller(QObject *parent) : ControllerSimpleSource (parent)
{
    this->setCurrentState(false);
    stateChangeTimer = new QTimer(this);

    QObject::connect(stateChangeTimer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
    stateChangeTimer->start(1000);
    qDebug() << "Source Node Started: ";
}

Controller::~Controller()
{
    stateChangeTimer->stop();
}

void Controller::testFunction(QString string)
{
    qDebug() << "Test function: " << string;
}

bool Controller::currentState() const
{
    return m_currentState;
}

void Controller::setCurrentState(bool currentState)
{
    m_currentState = currentState;
    emit currentStateChanged(m_currentState);
}

void Controller::timeout_slot()
{
    qDebug() << "Source state is: " << currentState();
}
