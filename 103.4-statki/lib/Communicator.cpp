#include "Communicator.h"
#include <sstream>


void Communicator::turnMsg(std::shared_ptr<Player> p) {
    std::stringstream message;
    message << "Gracz " << p->getName() << "\n";
    logMessage(message.str());
}

void Communicator::showMaps(std::shared_ptr<Player> p) {
    std::stringstream mapsMessage;
    mapsMessage << p->getMyMap().getMapAsString() << "\n"
                << "-----------------------------------------\n"
                << p->getEnemyMap().getMapForEnemyAsString() << "\n"
                << "-----------------------------------------\n";
    logMessage(mapsMessage.str());
}

void Communicator::winMsg(std::shared_ptr<Player> p) {
    std::stringstream winMessage;
    winMessage << "Wygrał Król niech żyje król " << p->getName() << "\n";
    logMessage(winMessage.str());
}

void Communicator::welcomeMsg() {
    std::stringstream welcomeMessage;
    welcomeMessage << "Witaj w symulatorze wersja 1.1\n";
    logMessage(welcomeMessage.str());
}

void Communicator::loadNames(std::string& name1, std::string& name2) {
    std::cout << "Podaj imiona 2 graczy" << std::endl;
    std::cin >> name1 >> name2;

    std::stringstream namesMessage;
    namesMessage << "Imiona graczy: " << name1 << " i " << name2 << "\n";
    logMessage(namesMessage.str());
}

void Communicator::loadFilenames(std::string& filename1, std::string& filename2) {
    std::cout << "Podaj sciezke do mapy pierwszego gracza" << std::endl;
    std::cin >> filename1;
    std::cout << "Podaj sciezke do mapy drugiego gracza" << std::endl;
    std::cin >> filename2;

    std::stringstream filenamesMessage;
    filenamesMessage << "Scieżki do map: " << filename1 << " i " << filename2 << "\n";
    logMessage(filenamesMessage.str());
}

void Communicator::selectPlayers(std::shared_ptr<Player>& p, maps& playerMaps, const std::string& playerName) {
    while (true) {
        logMessage("Czy gracz ma być człowiekiem(1), losowym graczem(2), czy graczem AI(3)? Wpisz odpowiednią cyfrę:");
        int decision;
        std::cin >> decision;

        if (decision >= 1 && decision <= 3) {
            std::stringstream playerSelectionMessage;
            playerSelectionMessage << "Gracz wybrał typ gracza " << decision << "\n";
            logMessage(playerSelectionMessage.str());

            if (decision == 1) {
                HumanPlayer player(playerName, playerMaps);
                p = std::make_shared<HumanPlayer>(player);
            } else if (decision == 2) {
                RandomPlayer player(playerName, playerMaps);
                p = std::make_shared<RandomPlayer>(player);
            } else if (decision == 3) {
                AdvancedAIPlayer player(playerName, playerMaps);
                p = std::make_shared<AdvancedAIPlayer>(player);
            }
            break;
        } else {
            std::cout << "Nieprawidłowy wybór" << std::endl;
        }
    }
}

void Communicator::logMessage(const std::string& message) {
    std::cout << message << std::endl;
    logFile << message;
}

