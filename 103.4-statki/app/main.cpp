
#include <iostream>
#include <vector>
#include <memory>
#include "../lib/Field.h"
#include "../lib/Map.h"
#include "../lib/Ship.h"
#include "../lib/Game.h"
#include "../lib/Player.h"
#include "../lib/RandomPlayer.h"
#include "../lib/MapReader.h"
#include "../lib/Writer.h"

int main()
{
    // std::cout << "Witaj w symulatorze gry w statki ver 1.0\n";
    // Map testmap(5,5);
    // std::vector<std::pair<int,int>> pos;
    // int x,y;
    // for (int i=0; i < 5; i ++) {
    //     x = 0;
    //     y = i;
    //     pos.push_back(std::make_pair(x,y));
    // }
    // Ship ship1(pos);
    // testmap.placeShip(ship1);
    // Map testmap2(5,5);
    // std::vector<std::pair<int,int>> pos2;
    // for (int i=0; i < 5; i ++) {
    //     x = 0;
    //     y = i;
    //     pos2.push_back(std::make_pair(x,y));
    // }
    // Ship ship2(pos2);
    // testmap2.placeShip(ship2);
    // std::vector<Ship> ships1 = {ship1};
    // std::vector<Ship> ships2 = {ship2};
    // GameRules grules;
    // RandomPlayer p1("Michał", std::make_pair(testmap, testmap2), ships1);
    // RandomPlayer p2("Maciek",std::make_pair(testmap2, testmap), ships2);
    // Game g1(std::make_shared<RandomPlayer>(p1), std::make_shared<RandomPlayer>(p2), grules);
    // g1.startGame();
    // return 0;
    MapReader mr;
    Writer wr;
    std::string filenameMichal = "/home/michal/Desktop/103.4-statki/103.4-statki/app/testsmap.txt";
    std::vector<std::vector<char>> matrix = mr.readMap(filenameMichal);
    auto mapa =  mr.createMap(filenameMichal);
    mapa.show();
    wr.writeMapToFile(mapa, "newmap.txt");
//    for(size_t i = 0; i < matrix.size(); i++){
//        for(size_t j = 0; j<matrix[i].size(); j++) {
//            std::cout << matrix[i][j] << '\t';
//        }
//        std::cout << std::endl;
//    }
//
//    std::cout << std::endl << std::endl;
//
//    std::vector<std::string> vecstr = mr.readMapMatrixstr(filenameMichal);
//    for(size_t i = 0; i < vecstr.size(); i++) {
//        std::cout << vecstr[i] << std::endl;
//    }


}


