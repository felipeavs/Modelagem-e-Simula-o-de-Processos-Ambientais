#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOW_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOW_H

/**
 * \file Flow.h
 * \brief Interface Classe Flow
 */

#include "System.h"

using namespace std;

class Flow {

public:

    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual System *getSystemSource() const = 0;
    virtual void setSystemSource(System *source) = 0;
    virtual System *getSystemDestination() const = 0;
    virtual void setSystemDestination(System *destination) = 0;
    virtual double execute() = 0;
    virtual bool operator==(const Flow &flow) const = 0;
    virtual bool operator!=(const Flow &flow) const = 0;
    virtual Flow&operator=(const Flow &flow) = 0;
    friend ostream &operator<<(ostream &os, Flow &flow);

};


#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOW_H
