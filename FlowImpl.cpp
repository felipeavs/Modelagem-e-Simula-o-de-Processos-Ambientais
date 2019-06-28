/**
 * \file FlowImpl.cpp
 * \brief Implementacao da  Classe FlowImpl
 */


#include "FlowImpl.h"

/** \brief Construtor de Flow
 */
FlowImpl::FlowImpl() {}


/** \brief Construtor de Flow com parametros
 *
 * @param name (string) Nome do Fluxo
 * @param source (System) Sistema de partida de fluxo
 * @param destination (System) Sistema de destino de fluxo
 */
FlowImpl::FlowImpl(const string &name, System *source, System *destination) :
        name(name), source(source), destination(destination) {}

/** \brief Construtor de copia de Flow
 *
 * @param flow
 */
FlowImpl::FlowImpl(Flow &flow) {

    if(this == &flow)
        return;
    this->setName(flow.getName());
    this->setSystemSource(flow.getSystemSource());
    this->setSystemDestination(flow.getSystemDestination());
}

/** \brief Destrutor de Flow
 */
FlowImpl::~FlowImpl() {

}

/** \brief Retorna name de Flow
 *
 * @return name (Flow)
 */
const string &FlowImpl::getName() const {
    return name;
}

/** \brief Altera nome de Flow
 *
 * @param name (sting)
 */
void FlowImpl::setName(const string &name) {
    FlowImpl::name = name;
}


/** \brief Retorna sistema de partida
 *
 * @return system de Partida
 */
System *FlowImpl::getSystemSource() const {
    return source;
}

/** \brief Altera sistema de partida
 *
 * @param source
 */
void FlowImpl::setSystemSource(System *source) {
    FlowImpl::source = source;
}

/** \brief Retorna sistema de destino
 *
 * @return system de Destino
 */
System *FlowImpl::getSystemDestination() const {
    return destination;
}

/** \brief Altera sistema de destino
 *
 * @param destination
 */
void FlowImpl::setSystemDestination(System *destination) {
    FlowImpl::destination = destination;
}

/** \brief Sobrecarda do operador de igualdade
 *
 * @param flow
 * @return bool Verdadeiro se for igual
 */
bool FlowImpl::operator==(const Flow &flow) const {
    return name == flow.getName() &&
           source == flow.getSystemSource() &&
           destination == flow.getSystemDestination();
}

/** \brief Sobrecarga de operador da diferença de flow
 *
 * @param flow
 * @return bool Verdadeiro se for diferente
 */
bool FlowImpl::operator!=(const Flow &flow) const {
    return !(flow == *this);
}

/** \brief Sobrecarga de operador de copia de Flow
 *
 * @param flow
 * @return copia de flow
 */
Flow& FlowImpl::operator=(const Flow &flow){

    if(this == &flow)
        return *this;

    this->setName(flow.getName());
    this->setSystemSource(flow.getSystemSource());
    this->setSystemDestination(flow.getSystemDestination());

    return *this;

}

/** \brief Sobrecarga do operador  de impressão da Classe Flow
     *
     * @param os
     * @param flow
     * @return Impressão de Flow
     */
ostream &operator<<(ostream &os, Flow &flow) {


    os << "Name Flow: " << flow.getName() << endl
       << "Source System: " << endl
       << *flow.getSystemSource() << endl
       << "Destination System: " << endl
       << *flow.getSystemDestination();

    return os;
}
