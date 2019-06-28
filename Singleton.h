#ifndef MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SINGLETON_H
#define MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SINGLETON_H

/**
 * \file Singleton.h
 * \brief Classe tamplate de Singleton
 */

#include "ModelImpl.h"

template <class T>
class Singleton {

private:

    Singleton(const Singleton&) = delete;
    Singleton&operator=(const Singleton&){ return *this;}

public:

    Singleton(){
    }

    /** \brief Permite que seja instanciado uma unica vez
     *
     * @return instance
     */
    static T* getSingleton(){
        if(instance == 0)
            instance = new T;
        return instance;
    }

    virtual ~Singleton(){
        delete instance;
    }

protected:
    static T* instance;

};


#endif //MODELO_E_SIMULACAO_DE_PROCESSOS_AMBIENTAIS_SINGLETON_H
