#pragma once
enum class FieldStatus : char {
    x = 'x',
    zero = '0',
    one = '1'
};
class Field {
private:
    int x_ ,y_;
    FieldStatus status_;
    bool isHidden_;
public:
    Field(int x = 0, int y = 0, FieldStatus state = FieldStatus::zero, bool isHidden = true);
    FieldStatus getStatus() const;
    int getx() const;
    int gety() const;
    bool isHidden() const;
    void setStatus(FieldStatus status);
    void setHidden(bool change);
    char getStatusToDisplay();
};