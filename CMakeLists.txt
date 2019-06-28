cmake_minimum_required(VERSION 3.10)
project(ModeloESimulacaoDeProcessosAmbientais)

set(CMAKE_CXX_STANDARD 11)

add_executable(ModeloESimulacaoDeProcessosAmbientais main.cpp SystemImpl.cpp SystemImpl.h System.h ModelImpl.cpp ModelImpl.h Model.h FlowImpl.cpp FlowImpl.h Flow.h TestesFuncionais/FuncionalTeste.h Singleton.h)