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

void Communicator::loadNames(std::string& name1, std::string& name2) {
    std::cout << "Podaj imiona 2 graczy" << std::endl;
    std::cin >> name1 >> name2;
}

void Communicator::loadFilenames(std::string& filename1, std::string& filename2) {
    std::cout << "Podaj sciezke do mapy pierwszego gracza" << std::endl;
    std::cin >> filename1;
    std::cout << "Podaj sciezke do mapy drugiego gracza" << std::endl;
    std::cin >> filename2;
}

void Communicator::selecPlayers(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2,
     maps maps1, maps maps2, std::string name1, std::string name2) {
    while(true) {
        std::cout << "Czy gracz pierwszy ma być człowiekiem(1), losowym graczem(2), czy graczem AI(3)? Wpisz odpowiednia cyfre:" << std::endl;
        int decision;
        std::cin >> decision;
        if(decision == 1) {
            HumanPlayer player1(name1, maps1);
            p1 = std::make_shared<HumanPlayer>(player1);
            break;
        }
        else if(decision == 2) {
            RandomPlayer player1(name1, maps1);
            p1 = std::make_shared<RandomPlayer>(player1);
            break;
        }
        else if(decision == 3) {
            AdvancedAIPlayer player1(name1, maps1);
            p1 = std::make_shared<AdvancedAIPlayer>(player1);
            break;
        }
        std::cout << "Nieprawidłowy wybór" << std::endl;
    }
    while(true) {
        std::cout << "Czy gracz drugi ma być człowiekiem(1), losowym graczem(2), czy graczem AI(3)? Wpisz odpowiednia cyfre:" << std::endl;
        int decision;
        std::cin >> decision;
        if(decision == 1) {
            HumanPlayer player2(name1, maps2);
            p2 = std::make_shared<HumanPlayer>(player2);
            break;
        }
        else if(decision == 2) {
            RandomPlayer player2(name1, maps2);
            p2 = std::make_shared<RandomPlayer>(player2);
            break;
        }
        else if(decision == 3) {
            AdvancedAIPlayer player2(name1, maps2);
            p2 = std::make_shared<AdvancedAIPlayer>(player2);
            break;
        }
        std::cout << "Nieprawidłowy wybór" << std::endl;
    }
}