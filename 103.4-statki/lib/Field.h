#pragma once
class Field {
private:
    int x_ ,y_;
    bool isTakenByShip_;
public:
    Field(int x, int y, bool isTakenByShip);
};