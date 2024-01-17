#include "Communicator.h"

void Communicator::turnMsg(std::shared_ptr<Player> p) {
    std::cout << "Gracz" << p->getName() << "\n";
}

void Communicator::showMaps(std::shared_ptr<Player> p) {
    p->getMyMap().show();
    std::cout<<"\n-----------------------------------------\n";
    p->getEnemyMap().showForEnemy();
    std::cout<<"\n-----------------------------------------\n";
}

void Communicator::winMsg(std::shared_ptr<Player> p) {
    std::cout<<"Wygrał Król niech żyje król " <<p->getName() << "\n";
}

void Communicator::welcomeMsg() {
    std::cout << "Witaj w symulatorze wersja 1.1\n";
}