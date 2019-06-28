#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEM_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEM_H

/**
 * \file System.h
 * \brief Interface Classe System
 */

#include <iostream>
#include <string>

///Classe System
using  namespace std;

class System {

public:

    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual double getResource() const = 0;
    virtual void setResource(double resource) = 0;
    virtual bool operator==(const System &rhs) const = 0;
    virtual bool operator!=(const System &rhs) const = 0;
    virtual System&operator=(const System& system) = 0;
    friend ostream &operator<<(ostream &os, const System &system1);
};

#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SYSTEM_H
