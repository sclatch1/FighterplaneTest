//
// Created by david Scalais on 24/02/2022.
//

#ifndef FIGHTERPLANE_H
#define FIGHTERPLANE_H

class FighterplaneTest;

class Fighterplane {

private:
    std::string callsign;
    int x; //positional coordinate
    int y; //positional coordinate
    int z; //positional coordinate
    int ammo; //keeps track of the number of missiles
    int health; //the remaining hitpoints the plane still has. When this reaches 0 the plane is dead!
public:
    friend class FighterplaneTest;
    Fighterplane();
    Fighterplane(std::string callsign, int x, int y, int z);
    std::string getCallSign();
    int getCoords();
    int getY();
    int getZ();
    int getAmmo();
    int getHealth();
    void moveTo(int x_new, int y_new, int z_new);
    void attackPlane(Fighterplane* target);
    void printToFile(const char * filename);
};


#endif //FIGHTERPLANE_H
