//
// Created by dev on 29/12/23.
//

#ifndef CMAKESFMLPROJECT_SPACESHIP_H
#define CMAKESFMLPROJECT_SPACESHIP_H

namespace game {

    class SpaceShip {
    public:
        SpaceShip();
        ~SpaceShip();
        void render();
        void update();
        void move();
        void attack();
        void takeDamage();
        void die();
        void levelUp();
        void gainXp();
        void gainMoney();
        void gainResources();
        void gainEnergy();
        void gainHealth();
        void gainSpeed();
        void gainDamage();
        void gainRange();
        void gainCost();
        void gainLevel();
        void gainXpToNextLevel();
        void gainType();
        void gainId();
        void gainOwner();
        void gainTarget();
        void gainTargetX();
        void gainTargetY();
        void gainTargetId();
        void gainTargetOwner();
        void gainTargetHp();
        void gainTargetSpeed();
        void gainTargetDamage();
        void gainTargetRange();
        void gainTargetCost();
        void gainTargetLevel();
        void gainTargetXp();
        void gainTargetXpToNextLevel();
    private:
        int x;
        int y;
        int hp;
        int speed;
        int damage;
        int range;
        int cost;
        int level;
        int xp;
        int xpToNextLevel;
        int type;
        int id;
        int owner;
        int target;
        int targetX;
        int targetY;
        int targetId;
        int targetOwner;
        int targetHp;
        int targetSpeed;
        int targetDamage;
        int targetRange;
        int targetCost;
        int targetLevel;
        int targetXp;
        int targetXpToNextLevel;
    };

} // game

#endif //CMAKESFMLPROJECT_SPACESHIP_H
