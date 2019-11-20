TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
SOURCES += \
        main.cpp

HEADERS += \
    field_types.hpp \
    fields_factory.h \
    message_types.h \
    template_factories.h
