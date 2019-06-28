#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEMIMPL_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEMIMPL_H

/**
 * \file SystemImpl.h
 * \brief Implementacao da classe System
 */

#include "System.h"

using  namespace std;

class SystemImpl: public System {

protected:
    string name;
    double resource;

public:

    SystemImpl();
    SystemImpl(const string &name, double resource);
    SystemImpl(const System& system);
    virtual ~SystemImpl();

    const string &getName() const;
    void setName(const string &name);
    double getResource() const;
    void setResource(double resource);

    bool operator==(const System &rhs) const;
    bool operator!=(const System &rhs) const;
    System&operator=(const System& system);

    friend ostream &operator<<(ostream &os, const System &system1);

};

#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEMIMPL_H
