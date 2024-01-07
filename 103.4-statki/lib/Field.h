#pragma once
class Field {
private:
    int x_ ,y_;
    bool isTakenByShip_;
    bool isHidden_;
public:
    Field(int x = 0, int y = 0, bool isTakenByShip = false, bool isHidden = true);
    bool isTakenByShip() const;
    int getx() const;
    int gety() const;
    bool isHidden() const;
    void setTakenByShip(bool change);
};