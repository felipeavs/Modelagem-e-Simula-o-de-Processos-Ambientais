#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODEL_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODEL_H


/**
 * \file Model.h
 * \brief Interface Classe Model
 */

#include <vector>
#include "FlowImpl.h"

using namespace std;

typedef typename vector<Flow*>::iterator iteratorFlow;
typedef typename vector<System*>::iterator iteratorSystem;

class Model{

public:

    virtual System* createSystem(string, double) = 0;
    template<typename T>
    Flow* createFlow(string name, System* systemSource, System* systemDestination){
        FlowImpl* flow = new T(name, systemSource, systemDestination);
        addFlow(flow);
        return flow;
    }
    static Model* createModel(string name, int initialTime, int finalTime);

    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual int getInitialTime() const = 0;
    virtual void setInitialTime(int initialTime) = 0;
    virtual int getFinalTime() const = 0;
    virtual void setFinalTime(int finalTime) = 0;
    virtual void simulate() = 0;
    virtual void report() = 0;

    virtual bool operator==(Model &model) = 0;
    virtual Model&operator=(Model &model) = 0;

    virtual iteratorFlow beginFlows() = 0;
    virtual iteratorFlow endFlows() = 0;
    virtual iteratorSystem beginSystems() = 0;
    virtual iteratorSystem endSystems() = 0;

protected:

    virtual void addFlow(Flow* flow) = 0;
    virtual void removeFlow(Flow* flow) = 0;
    virtual void addSystem(System* system)=0;
    virtual void removeSystem(System* system)=0;
};


#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_MODEL_H
