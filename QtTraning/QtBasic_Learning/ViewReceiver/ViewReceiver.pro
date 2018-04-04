QT += network widgets
QT += opengl

HEADERS       = receiver.h \
    glwidget.h
SOURCES       = receiver.cpp \
                main.cpp \
    glwidget.cpp

# install
target.path = ./bin
INSTALLS += target

