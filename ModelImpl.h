#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODELIMPL_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODELIMPL_H

/**
 * \file ModelImpl.h
 * \brief Implementacao da classe Model
 */

#include "Model.h"
#include "SystemImpl.h"
#include "Singleton.h"

using namespace std;

class ModelImpl : public Model, public Singleton<ModelImpl>{

private:
    string name;
    vector<Flow*> flows;
    vector<System*> systems;
    int initialTime;
    int finalTime;

public:

    System* createSystem(string, double);
    static Model* createModel(string name, int initialTime, int finalTime);

    //CONTRUTORES
    ModelImpl();
    //ModelImpl(const string &name, int initialTime, int finalTime);
    ModelImpl(Model& model);
    virtual ~ModelImpl();

    //SETTERS E GETTERS
    const string &getName() const;
    void setName(const string &name);
    int getInitialTime() const;
    void setInitialTime(int initialTime);
    int getFinalTime() const;
    void setFinalTime(int finalTime);

    //ADD  e REMOVE - FLUXOS E SYSTEMAS
    void addFlow(Flow* flow);
    void removeFlow(Flow* flow);
    void addSystem(System* system);
    void removeSystem(System* system);

    //SIMULADOR DE MODELO
    void simulate();

    //SOBRECARGAS
    bool operator==(Model &model);
    Model&operator=(Model &model);

    void report();

    //ITERADORES
    iteratorFlow beginFlows();
    iteratorFlow endFlows();
    iteratorSystem beginSystems();
    iteratorSystem endSystems();

};

#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODELIMPL_H
