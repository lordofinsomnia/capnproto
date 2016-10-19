TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    addressbook.capnp.c++

DISTFILES += \
    addressbook.capnp

HEADERS += \
    addressbook.capnp.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lcapnp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lcapnp
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lcapnp
