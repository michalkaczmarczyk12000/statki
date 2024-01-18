#pragma once 
#include <fstream>
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "AdvancedAIPlayer.h"
#include "MapReader.h"
#include "Writer.h"
#include "CannotOpenFileError.h"
class Communicator {
public:
    Communicator(const std::string& logFileName) : logFile(logFileName) {
        if (!logFile.is_open()) {
            throw CannotOpenFileError("Błąd pliku");
        }
    }
    Communicator() = default;

    ~Communicator() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void logMessage(const std::string& message);
    void saveMapsToFile(const std::shared_ptr<Player>& p);
    void saveToFile(const std::string& filename, const std::string& content);

    void turnMsg(std::shared_ptr<Player> p);
    void showMaps(std::shared_ptr<Player> p);
    void winMsg(std::shared_ptr<Player> p);
    void welcomeMsg();
    void loadNames(std::string& name1, std::string& name2);
    void loadFilenames(std::string& filename1, std::string& filename2);
    void selectPlayers(std::shared_ptr<Player>& p, maps& playerMaps, const std::string& playerName);
    Coordinates getCoords() const;
    int makeDecision() const;
    orientation getOrientation() const;
    int getShipId() const;
    void alert(std::string alert);
private:
    std::ofstream logFile;
};
