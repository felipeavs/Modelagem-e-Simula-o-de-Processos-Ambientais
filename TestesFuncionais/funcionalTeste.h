#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FUNCIONALTESTE_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FUNCIONALTESTE_H

#include <iostream>
#include "../Model.h"
#include <cassert>
#include <cmath>

using namespace std;

class LogisticFlow: public FlowImpl{
public:
    LogisticFlow();
    LogisticFlow(string name, System *source, System *destination): FlowImpl(name, source, destination){}
    ~LogisticFlow(){}
    double execute(){
        return (0.01 * (getSystemDestination()->getResource())) * (1 - (getSystemDestination()->getResource())/70);
    }
};

class ExponentialFlow: public FlowImpl{
public:
    ExponentialFlow(){}
    ExponentialFlow(string name, System *source, System *destination): FlowImpl(name, source, destination){}
    ~ExponentialFlow(){}
    double execute(){
        return ((getSystemSource()->getResource())*0.01);
    }
};

void testeFuncional1(){

    //Exponential
    Model* model = Model::createModel("TesteFuncional1",0,100);
    System* Q1 = model->createSystem("POP1", 100);
    System* Q2 = model->createSystem("POP2", 0);
    Flow* f1 =  model->createFlow<ExponentialFlow>("Exponencial", Q1, Q2);

    model->simulate();

    assert(fabs(Q1->getResource()-36.6032)<0.0001);
    assert(fabs(Q2->getResource()-63.3968)<0.0001);

}

void testeFuncional2(){

    //Logistic
    Model* model = Model::createModel("TesteFuncional2", 0, 100);
    System* Q1 = model->createSystem("P1", 100);
    System* Q2 = model->createSystem("P2", 10);
    Flow* f1 =  model->createFlow<LogisticFlow>("Logistic", Q1, Q2);

    model->simulate();

    assert(fabs(Q1->getResource()-88.2167)<0.0001);
    assert(fabs(Q2->getResource()-21.7834)<0.0001);
}

void testeFuncional3(){

    Model* model = Model::createModel("TesteFuncional3", 0, 100);
    System* Q1 = model->createSystem("Q1", 100);
    System* Q2 = model->createSystem("Q2", 0);
    System* Q3 = model->createSystem("Q3", 100);
    System* Q4 = model->createSystem("Q4", 0);
    System* Q5 = model->createSystem("Q5", 0);

    Flow* f =  model->createFlow<ExponentialFlow>("Exponencial_F", Q1, Q2);
    Flow* g =  model->createFlow<ExponentialFlow>("Exponencial_G", Q1, Q3);
    Flow* r =  model->createFlow<ExponentialFlow>("Exponencial_R", Q2, Q5);
    Flow* t =  model->createFlow<ExponentialFlow>("Exponencial_T", Q2, Q3);
    Flow* u =  model->createFlow<ExponentialFlow>("Exponencial_U", Q3, Q4);
    Flow* v =  model->createFlow<ExponentialFlow>("Exponencial_V", Q4, Q1);

    model->simulate();

    assert(fabs(Q1->getResource()-31.8513)<0.0001);
    assert(fabs(Q2->getResource()-18.4003)<0.0001);
    assert(fabs(Q3->getResource()-77.1143)<0.0001);
    assert(fabs(Q4->getResource()-56.1728)<0.0001);
    assert(fabs(Q5->getResource()-16.4612)<0.0001);


}

#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FUNCIONALTESTE_H
