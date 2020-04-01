QT += quick remoteobjects network
CONFIG += c++11

include(../common/common.pri)

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/main.cpp \
        src/Controller.cpp

HEADERS += \
        src/Controller.h

REPC_DIR=../common/reps
REPC_SOURCE = $$REPC_DIR/Controller.rep \


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
