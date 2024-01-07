#pragma once
class Field {
private:
    int x_ ,y_;
    bool isTakenByShip_;
public:
    Field(int x = 0, int y = 0, bool isTakenByShip = false);
    bool getIsTakenByShip();
    int getx();
    int gety();
};