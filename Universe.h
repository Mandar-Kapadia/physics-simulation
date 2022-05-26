/*Copyright 2022  Mandar Kapadia */
#include "CelestialBody.h"//NOLINT
#include<memory>//NOLINT
#include<vector>//NOLINT

class Universe:public sf::Drawable {
 public:
        Universe(double xViewPoint, double yViewPoint);
        friend std::istream& operator>> (std::istream& in, Universe& temp);
        void step(double time);
 private:
    void calculations(int i, int j, double time);
    std::vector<std::shared_ptr<CelestialBody>> pCB;
    double xViewPoint;
    double yViewPoint;
    int planets;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;//NOLINT
};
