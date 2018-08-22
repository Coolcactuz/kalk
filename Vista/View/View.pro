######################################################################
# Automatically generated by qmake (3.1) Wed Aug 22 15:28:38 2018
######################################################################

TEMPLATE = app
TARGET = View
INCLUDEPATH += .
QT+=widgets

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += KalkButton.h \
           startup_view.h \
           "specialized view hierarchy/specialized_view.h" \
           "specialized view hierarchy/VCircuit.h" \
           "specialized view hierarchy/VComplex.h" \
           "specialized view hierarchy/VNota.h" \
           "specialized view hierarchy/VNumTypes.h" \
           "specialized view hierarchy/VRaz.h"
SOURCES += main.cpp \
           startup_view.cpp \
           "specialized view hierarchy/specialized_view.cpp" \
           "specialized view hierarchy/VCircuit.cpp" \
           "specialized view hierarchy/VComplex.cpp" \
           "specialized view hierarchy/VNumTypes.cpp" \
           "specialized view hierarchy/VRaz.cpp"