#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOWIMPL_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOWIMPL_H

/**
 * \file FlowImpl.h
 * \brief Implementacao da Classe Flow
 */

#include "Flow.h"

class FlowImpl: public Flow {

private:
    string name;
    System* source;
    System* destination;

public:

    FlowImpl();
    FlowImpl(const string &name, System *source, System *destination);
    FlowImpl(Flow& flow);
    virtual ~FlowImpl();

    const string &getName() const;
    void setName(const string &name);
    System *getSystemSource() const;
    void setSystemSource(System *source);
    System *getSystemDestination() const;
    void setSystemDestination(System *destination);

    virtual double execute()=0;

    bool operator==(const Flow &flow) const;
    bool operator!=(const Flow &flow) const;
    Flow&operator=(const Flow &flow);

    friend ostream &operator<<(ostream &os, Flow &flow);

};

#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_FLOWIMPL_H
