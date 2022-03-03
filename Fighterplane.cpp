//
//  Fighterplane.cpp
//
//  Created by Quinten Soetens on 13/02/14.
//  Copyright (c) 2014 Quinten Soetens. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "Fighterplane.h"
#include "Designbycontract.h"




    //Default constructor will place a new plane with no name at location (0,0,0)
    Fighterplane::Fighterplane()
    {
    this->callsign = "";
    this->x = 0;
    this->y = 0;
    this->z = 0;
    }


    //constructor to set a plane on a certain location.
    //ammo and healt are automaticalle initialized to 10 and 20 respectively
    Fighterplane::Fighterplane(std::string callsign, int x, int y, int z) : ammo(10), health(20){
        this->callsign = callsign;
        this->x = x;
        this->y = y;
        this->z = z;
    }

std::string Fighterplane::getCallSign() {
        return callsign;
    }

    //Obtain positional coordinate in string format
    int Fighterplane:: getCoords(){
    return x;
    }
    //Getter to obtain positional coordinate
    int Fighterplane::getY(){
        return y;
    }
    //Getter to obtain positional coordinate
    int Fighterplane::getZ(){
        return z;
    }
    int Fighterplane::getAmmo() {
        return ammo;
    }
    int Fighterplane::getHealth() {
        return health;
    }

    //Method that allows a plane to move to a new location.
    void Fighterplane::moveTo(int x_new, int y_new, int z_new){
        this->x += x_new;
        this->y += y_new;
        this->z += z_new;
    }

    //Method to attack another plane.
    void Fighterplane::attackPlane(Fighterplane* target){
    REQUIRE(ammo >= 0, "ammo is negatief")  ;
    this->ammo -= 1;
        target->health -= 5;

}

    //Prints all the information about this fighterplane to a file.
    void Fighterplane::printToFile(const char * filename){
        std::ofstream outfile;
        outfile.open (filename);
        outfile << "Information about Fighterplane: \n";
        outfile << "Callsign: " + callsign + "\n";
        outfile << "Position: (" << x << "," << y << "," << z << ")\n";
        outfile << "Health: " << health << "\n";
        outfile << "Remaining ammo: " << ammo << "\n";
        outfile.close();
    }