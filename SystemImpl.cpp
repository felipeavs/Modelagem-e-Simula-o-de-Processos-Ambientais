/**
 * \file SystemImpl.cpp
 * \brief Implementacao da  Classe SystemImpl
 */


#include "SystemImpl.h"


/** \brief Construtor de System
 *
 */
SystemImpl::SystemImpl(){

}

/** \brief  Construtor de System passando como parametro uma string, para o nome, e um double, para o recurso.
 *
 * @param name (string)
 * @param resource (double)
 */
SystemImpl::SystemImpl(const string &name, double resource) :
        name(name), resource(resource) {

}

/** \brief Construtor de Cópia de System
 *
 * @param system
 */
SystemImpl::SystemImpl(const System &system) {

    if(this == &system)
        return;

    this->setName(system.getName());
    this->setResource(system.getResource());
}

/** \brief Destrutor de System
 */
SystemImpl::~SystemImpl() {

}

/** \brief Retorna o nome(string) de System
 *
 * @return name(string)
 */
const string &SystemImpl::getName() const {
    return name;
}

/** \brief Altera o nome(string) de System
 *
 * @param name
 */
void SystemImpl::setName(const string &name) {
    SystemImpl::name = name;
}

/** \brief Retorna o valor(double) do recurso de System
 *
 * @return recurso(doule)
 */
double SystemImpl::getResource() const {
    return resource;
}

/** \brief Altera o valor(double) do recurso de System
 *
 * @param resource (double)
 */

void SystemImpl::setResource(double resource) {
    SystemImpl::resource = resource;
}

/** \brief Sobrecarga do operador de igualdade da Classe System
 *
 * @param system
 * @return Retona bool se o objeto for igual do que foi passado como parametro
 */

bool SystemImpl::operator==(const System &system) const {
    return name == system.getName() &&
           resource == system.getResource();
}

/** \brief Sobrecarga do operador de diferença da classe System
 *
 * @param system
 * @return Retona bool se o objeto for diferende do que foi passado como parametro
 */

bool SystemImpl::operator!=(const System &system) const {
    return !(system == *this);
}

/** \brief Sobrecarga do operador de copia da Classe System
 *
 * @param system
 * @return Retorna um objeto de System como cópia
 */
System& SystemImpl::operator=(const System& system){

    if(this == &system)
        return *this;

    this->setName(system.getName());
    this->setResource(system.getResource());

    return *this;
}

/** \brief Sobrecarga do operador  de impressão da Classe System
     *
     * @param os
     * @param system
     * @return Impressão de System
     */

ostream &operator<<(ostream &os, const System &system) {

    os << "System name: " << system.getName() << endl
       << "System resource: " << system.getResource();

    return os;
}
