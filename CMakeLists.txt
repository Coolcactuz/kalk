cmake_minimum_required(VERSION 3.12)
project(kalk)

set(CMAKE_CXX_STANDARD 14)

include_directories(Controller)
include_directories(Extra)
include_directories(Model)
include_directories("testing controller view/Controller")
include_directories("testing controller view/View")
include_directories("testing controller view/View/p2/specialized view hierarchy")
include_directories("testing controller view/View/specialized view hierarchy")
include_directories(View)

add_executable(kalk
    Controller/controller.cpp
    Controller/controller.h
    Controller/filesize.cpp
    Controller/ideas_controller.txt
    Controller/session_buffer.h
    Controller/test.txt
    Extra/Dato.h
    Extra/parser.cpp
    Extra/parser.h
    Model/C_cartesiano.cpp
    Model/C_cartesiano.h
    Model/C_cartesiano.o
    Model/C_polare.cpp
    Model/C_polare.h
    Model/C_polare.o
    Model/Circuito.cpp
    Model/Circuito.h
    Model/Circuito.o
    Model/Complesso.cpp
    Model/Complesso.h
    Model/Complesso.o
    Model/Componente.cpp
    Model/Componente.h
    Model/Componente.o
    Model/Condensatore.cpp
    Model/Condensatore.h
    Model/Condensatore.o
    Model/exception.h
    Model/Induttore.cpp
    Model/Induttore.h
    Model/Induttore.o
    Model/kalk
    Model/main.cpp
    Model/main.o
    Model/makefile
        Model/model.dia
    Model/model_uml.dia
        Model/Numero.cpp
    Model/Numero.h
    Model/Numero.o
    Model/parser.h
    Model/Raz.cpp
    Model/Raz.h
    Model/Raz.o
    Model/Resistore.cpp
    Model/Resistore.h
    Model/Resistore.o
    "testing controller view/Controller/controller.cpp"
    "testing controller view/Controller/controller.h"
    "testing controller view/Controller/session_buffer.h"
    "testing controller view/View/p2/drawings/complex/complex"
    "testing controller view/View/p2/drawings/complex/complex.cpp"
    "testing controller view/View/p2/drawings/complex/complex.o"
    "testing controller view/View/p2/drawings/complex/complex.pro"
    "testing controller view/View/p2/drawings/complex/Makefile"
    "testing controller view/View/p2/drawings/raz/Makefile"
    "testing controller view/View/p2/drawings/raz/raz"
    "testing controller view/View/p2/drawings/raz/raz.cpp"
    "testing controller view/View/p2/drawings/raz/raz.o"
    "testing controller view/View/p2/drawings/raz/raz.pro"
    "testing controller view/View/p2/specialized view hierarchy/KalkButton.h"
    "testing controller view/View/p2/specialized view hierarchy/main.cpp"
    "testing controller view/View/p2/specialized view hierarchy/main.o"
    "testing controller view/View/p2/specialized view hierarchy/Makefile"
    "testing controller view/View/p2/specialized view hierarchy/moc_KalkButton.cpp"
    "testing controller view/View/p2/specialized view hierarchy/moc_KalkButton.o"
    "testing controller view/View/p2/specialized view hierarchy/moc_predefs.h"
    "testing controller view/View/p2/specialized view hierarchy/specialized view hierarchy"
    "testing controller view/View/p2/specialized view hierarchy/specialized view hierarchy.pro"
    "testing controller view/View/p2/specialized view hierarchy/specialized_view.cpp"
    "testing controller view/View/p2/specialized view hierarchy/specialized_view.h"
    "testing controller view/View/p2/specialized view hierarchy/specialized_view.o"
    "testing controller view/View/p2/specialized view hierarchy/VCircuit.cpp"
    "testing controller view/View/p2/specialized view hierarchy/VCircuit.h"
    "testing controller view/View/p2/specialized view hierarchy/VCircuit.o"
    "testing controller view/View/specialized view hierarchy/specialized_view.cpp"
    "testing controller view/View/specialized view hierarchy/specialized_view.h"
    "testing controller view/View/specialized view hierarchy/VCircuit.cpp"
    "testing controller view/View/specialized view hierarchy/VCircuit.h"
    "testing controller view/View/specialized view hierarchy/VComplex.cpp"
    "testing controller view/View/specialized view hierarchy/VComplex.h"
    "testing controller view/View/specialized view hierarchy/VNota.h"
    "testing controller view/View/specialized view hierarchy/VNumTypes.cpp"
    "testing controller view/View/specialized view hierarchy/VNumTypes.h"
    "testing controller view/View/specialized view hierarchy/VRaz.cpp"
    "testing controller view/View/specialized view hierarchy/VRaz.h"
    "testing controller view/View/KalkButton.h"
    "testing controller view/View/startup_view.cpp"
    "testing controller view/View/startup_view.h"
    "testing controller view/controller.o"
    "testing controller view/main.cpp"
    "testing controller view/main.o"
    "testing controller view/Makefile"
    "testing controller view/moc_controller.cpp"
    "testing controller view/moc_controller.o"
    "testing controller view/moc_KalkButton.cpp"
    "testing controller view/moc_KalkButton.o"
    "testing controller view/moc_specialized_view.cpp"
    "testing controller view/moc_specialized_view.o"
    "testing controller view/moc_startup_view.cpp"
    "testing controller view/moc_startup_view.o"
    "testing controller view/specialized_view.o"
    "testing controller view/startup_view.o"
    "testing controller view/testing controller view"
    "testing controller view/testing controller view.pro"
    "testing controller view/VCircuit.o"
    "testing controller view/VComplex.o"
    "testing controller view/VNumTypes.o"
    "testing controller view/VRaz.o"
    View/ideas_view.txt
    View/selectTypeButton.h
    View/startup_view.cpp
    View/startup_view.h
    View/view_manager.cpp
    View/view_manager.h
    main.cpp
    README.md
    specificaProgetto.pdf Model/Numerical_Hierarchy.cpp Model/Numerical_Hierarchy.h Model/Circuit_Hierarchy.cpp Model/Circuit_Hierarchy.h Model/Database_Hierarchy.cpp Model/Database_Hierarchy.h Model/Hierarchy_Handler.cpp Model/Hierarchy_Handler.h)
