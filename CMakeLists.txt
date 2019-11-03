cmake_minimum_required(VERSION 3.15)
project(projet_cpp_2019_BigLazyBrother)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/tcous/Documents/CEGEP_de_Matane/PROGRAMMATION DE MONDES VIRTUELS/2. C++/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/tcous/Documents/CEGEP_de_Matane/PROGRAMMATION DE MONDES VIRTUELS/2. C++/SFML-2.5.1/lib")
set(SFML_DIR "/home/tcous/Documents/CEGEP_de_Matane/PROGRAMMATION DE MONDES VIRTUELS/2. C++/SFML-2.5.1/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

include_directories(src)

add_executable(projet_cpp_2019_BigLazyBrother
        src/Gangster.cpp
        src/Gangster.h
        src/Gentil.cpp
        src/Gentil.h
        src/Mechant.cpp
        src/Mechant.h
        src/ProjetLuckyLukeLocal.cpp
        src/Sheriff.cpp
        src/Sheriff.h
        src/Affichage.cpp
        src/Affichage.h)
target_link_libraries (projet_cpp_2019_BigLazyBrother
        sfml-graphics
        sfml-window
        sfml-system)