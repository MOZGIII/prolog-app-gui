QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Set C++0x extesions
QMAKE_CXXFLAGS += -std=gnu++0x

# Load SWI-Pl
include(swipl-linkage.pri)

TARGET = prolog-app-gui
TEMPLATE = app

SOURCES += src/main.cpp\
    src/app.cpp \
    src/swipl_container.cpp \
    src/helpers.cpp \
    src/logger.cpp \
    src/logic.cpp

HEADERS  += src/app.h \
    src/swipl_container.h \
    src/prolog-api.h \
    src/helpers.h \
    src/logger.h \
    src/logic.h

FORMS    += forms/app.ui
