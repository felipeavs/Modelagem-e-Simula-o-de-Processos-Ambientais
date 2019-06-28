/**
 * \file ModelImpl.cpp
 * \brief Implementacao da  Classe ModelImpl
 */


#include "ModelImpl.h"

/** \brief Fabrica de System, cria e retorna um system
 *
 * @param name
 * @param resource
 * @return system
 */
System* ModelImpl::createSystem(string name, double resource){
    System* system = new SystemImpl(name,resource);
    addSystem(system);
    return system;
}

template <>
ModelImpl* Singleton<ModelImpl>::instance = 0;

/** \brief Retorna uma unica instancia de modelo
 *
 * @return singleton de model
 */
Model* ModelImpl::createModel(string name, int initialTime, int finalTime){
    Model* model = getSingleton();
    model->setName(name);
    model->setInitialTime(initialTime);
    model->setFinalTime(finalTime);
    return  model;
}

/** \brief Fabrica de modelo
 *
 * @return ponteiro da instancia de modelo
 */
Model* Model::createModel(string name, int initialTime, int finalTime) {
    return ModelImpl::createModel(name, initialTime, finalTime);
}

/** \brief Construtor de modelo
 *
 */
ModelImpl::ModelImpl(){

}

//ModelImpl::ModelImpl(const string &name, int initialTime, int finalTime) :
//        name(name), initialTime(initialTime), finalTime(finalTime) {}

/** \brief Construtor de copia de modelo
 *
 * @param model
 */
ModelImpl::ModelImpl(Model& model){

    if(this == &model)
        return;

    this->setName(model.getName());
    this->setInitialTime(model.getInitialTime());
    this->setFinalTime(model.getFinalTime());

    flows.clear();
    systems.clear();

    for(iteratorFlow it = beginFlows(); it != endFlows(); it ++){
        addFlow(*it);
    }

    for(iteratorSystem it = beginSystems(); it != endSystems(); it ++){
        addSystem(*it);
    }
}

/** \brief Destrutor de modelo
 *
 */
ModelImpl::~ModelImpl() {

    for(iteratorSystem it = beginSystems(); it != endSystems(); it ++){
        removeSystem(*it);
    }

    systems.clear();

    for(iteratorFlow it = beginFlows(); it != endFlows(); it ++){
        removeFlow(*it);
    }

    flows.clear();

}

/** \brief Retorna o nome do medelo
 *
 * @return name(string)
 */
const string &ModelImpl::getName() const {
    return name;
}

/** \brief Altera o nome de modelo
 *
 * @param name (string)
 */
void ModelImpl::setName(const string &name) {
    ModelImpl::name = name;
}

/** \brief Retorna o tempo inicial de model
 *
 * @return initialTime(int)
 */
int ModelImpl::getInitialTime() const {
    return initialTime;
}

/** \brief Altera o tempo inicial do modelo
 *
 * @param initialTime(int)
 */
void ModelImpl::setInitialTime(int initialTime) {
    ModelImpl::initialTime = initialTime;
}

/** \brief Retorna o tempo final de model
 *
 * @return finalTime(int)
 */
int ModelImpl::getFinalTime() const {
    return finalTime;
}

/** \brief Altera o tempo final do modelo
 *
 * @param finalTime(int)
 */
void ModelImpl::setFinalTime(int finalTime) {
    ModelImpl::finalTime = finalTime;
}

/** \brief Adiciona o Flow passado por parametro na ultima posição do vector de flow
 *
 */
void ModelImpl::addFlow(Flow* flow){
    this->flows.push_back(flow);
}

/** \brief Adiciona o System passado por parametro na ultima posição do vector de system
 *
 */
void ModelImpl::addSystem(System *system) {
    this->systems.push_back(system);
}

/** \brief Remove o Flow passado por parametro
 *
 * @param flow
 */
void ModelImpl::removeFlow(Flow* flow){
    delete flow;
}

/** \brief Remove o System passado por parametro
 *
 * @param system
 */
void ModelImpl::removeSystem(System* system){
    delete system;
}

/** \brief Simulação do modelo
 *
 */

void ModelImpl::simulate(){

    vector<double> result;
    System *Source;
    System *Destination;
    int j = 0;

    for(int i = getInitialTime(); i < getFinalTime(); i++){

        for(iteratorFlow it = beginFlows(); it != endFlows(); it++){
            result.push_back((*it)->execute());
        }

        int k = 0;
        for(iteratorFlow it = beginFlows(); it != endFlows(); it++){

            Source = flows[k]->getSystemSource();
            Source->setResource(Source->getResource() - result[j]);
            flows[k]->setSystemSource(Source);

            Destination = flows[k]->getSystemDestination();
            Destination->setResource(Destination->getResource() + result[j]);
            flows[k]->setSystemDestination(Destination);
            j++;
            k++;
        }
    }
}


/** \brief Sobregarga do operador de iguladade
 *
 * @param model
 * @return bool Verdadeiro se for igual
 */
bool ModelImpl::operator==(Model &model){

    bool comparaVec;
    iteratorFlow itParametro = model.beginFlows();
    for(iteratorFlow it = beginFlows(); it != endFlows(); it++){
        if(*it == *itParametro){
            comparaVec = true;
            itParametro++;
        }
        else
            return false;
    }

    return name == model.getName() &&
           initialTime == model.getInitialTime() &&
           finalTime == model.getFinalTime() &&
           comparaVec == true;
}

/** \brief Sobrecarga do operador igual
 *
 * @param model
 * @return copia de model
 */
Model& ModelImpl::operator=(Model &model){

    if(this == &model)
        return *this;

    this->setName(model.getName());
    this->setInitialTime(model.getInitialTime());
    this->setFinalTime(model.getFinalTime());

    flows.clear();
    systems.clear();

    for(iteratorFlow it = model.beginFlows(); it != model.endFlows(); it ++){
        addFlow(*it);
    }

    for(iteratorSystem it = model.beginSystems(); it != model.endSystems(); it ++){
        addSystem(*it);
    }

    return *this;
}

/** \brief Impressao de modelo
 *
 */
void ModelImpl::report(){
    cout << "\nModel Name: " << getName() << endl;
    cout << "Inicial time: " << getInitialTime() << endl;
    cout << "Final time: " << getFinalTime() << endl << endl;

    for(auto* flow: flows){
        cout << *flow;
    }
}


/** \brief Retorna o primiro iterador do vector de Flow
 *
 * @return primeiro iterador de Flow
 */
iteratorFlow ModelImpl::beginFlows(){
    return flows.begin();
}

/** \brief Retorna o ultimo iterador do vector de Flow
 *
 * @return ultimo iterador de Flow
 */
iteratorFlow ModelImpl::endFlows(){
    return flows.end();
}

/** \brief Retorna o primeiro iterador do vector de System
 *
 * @return primeiro iterador de System
 */
iteratorSystem ModelImpl::beginSystems(){
    return systems.begin();
}

/** \brief Retorna o ultimo iterador do vector de System
 *
 * @return ultimo iterador de System
 */
iteratorSystem ModelImpl::endSystems(){
    return systems.end();
}





