######################################################################
# Automatically generated by qmake (3.0) ven set 7 17:47:05 2018
######################################################################

QT += widgets
CONFIG += c++11
TEMPLATE = app
TARGET = KALK
INCLUDEPATH += .

# Input
HEADERS += Controller/controller.h \
           Model/C_cartesiano.h \
           Model/C_polare.h \
           Model/Circuit_Hierarchy.h \
           Model/Complesso.h \
           Model/Componente.h \
           Model/Condensatore.h \
           Model/Database_Hierarchy.h \
           Model/Dato.h \
           Model/exception.h \
           Model/Hierarchy_Handler.h \
           Model/Induttore.h \
           Model/Numerical_Hierarchy.h \
           Model/Numero.h \
           Model/parser.h \
           Model/Raz.h \
           Model/Resistore.h \
           Model/tupla.h \
           View/controller_view.h \
           View/items/KalkButton.h \
           View/items/KalkExceptionAlert.h \
           View/items/KalkHelpWindow.h \
           View/items/KalkPlainTextEdit.h \
           View/specialized_view_hierarchy/numerical_insert.h \
           View/specialized_view_hierarchy/specialized_view.h \
           View/specialized_view_hierarchy/VCircuito.h \
           View/specialized_view_hierarchy/VComplesso.h \
           View/specialized_view_hierarchy/VRazionale.h \
           View/specialized_view_hierarchy/VTupla.h \
           View/startup/startup_view.h
SOURCES += main.cpp \
           Controller/controller.cpp \
           Model/C_cartesiano.cpp \
           Model/C_polare.cpp \
           Model/Circuit_Hierarchy.cpp \
           Model/Complesso.cpp \
           Model/Componente.cpp \
           Model/Condensatore.cpp \
           Model/Database_Hierarchy.cpp \
           Model/Hierarchy_Handler.cpp \
           Model/Induttore.cpp \
           Model/Numerical_Hierarchy.cpp \
           Model/Numero.cpp \
           Model/Raz.cpp \
           Model/Resistore.cpp \
           Model/tupla.cpp \
           View/controller_view.cpp \
           View/items/KalkExceptionAlert.cpp \
           View/items/KalkHelpWindow.cpp \
           View/items/KalkPlainTextEdit.cpp \
           View/specialized_view_hierarchy/numerical_insert.cpp \
           View/specialized_view_hierarchy/specialized_view.cpp \
           View/specialized_view_hierarchy/VCircuito.cpp \
           View/specialized_view_hierarchy/VComplesso.cpp \
           View/specialized_view_hierarchy/VRazionale.cpp \
           View/specialized_view_hierarchy/VTupla.cpp \
           View/startup/startup_view.cpp
