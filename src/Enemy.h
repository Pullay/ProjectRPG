#ifndef ENEMY_H_
#define ENEMY_H_

#include <string>

class Enemy
{
    public:
        Enemy(std::string name, int x, int y);
        std::string getName() const;
        int getX() const;
        int getY() const;

    private:
        std::string name;
        int x, y;
};
#endif