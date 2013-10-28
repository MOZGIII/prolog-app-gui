QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Set C++0x extesions
QMAKE_CXXFLAGS += -std=gnu++0x

# Load SWI-Pl
include(swipl-linkage.pri)

TARGET = prolog-app-gui
TEMPLATE = app

SOURCES += main.cpp\
    app.cpp \
    swipl_container.cpp \
    helpers.cpp \
    logger.cpp

HEADERS  += app.h \
    swipl_container.h \
    prolog-api.h \
    helpers.h \
    logger.h

FORMS    += app.ui
