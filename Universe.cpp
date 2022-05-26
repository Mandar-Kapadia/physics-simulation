/*Copyright 2022  Mandar Kapadia */
#include "Universe.h" //NOLINT
#include<string>//NOLINT
Universe::Universe(double xViewPoint, double yViewPoint) {
    this->xViewPoint = xViewPoint;
    this->yViewPoint = yViewPoint;
}
std::istream& operator>> (std::istream& is, Universe& temp) {
    int planets;
    double radius;
    double xPos;
    double yPos;
    double yVol;
    double xVol;
    double mass;
    std::string filename;
    is >> planets >> radius;
    temp.planets = planets;
    for (int i = 0; i < planets; i++) {
       is >> xPos >> yPos >> xVol >> yVol >> mass >> filename;
       temp.pCB.push_back(std::make_shared<CelestialBody>(xPos, yPos, xVol, yVol, mass, filename, temp.xViewPoint, temp.yViewPoint, radius)); //NOLINT
    }
    return is;
}
void Universe::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    for (int i = 0; i < planets; i++) {
       target.draw(*pCB[i], states);
    }
}
void Universe::step(double time) {
const double gravity = -6.67e-11;
    for (int i = 0; i < planets; i++) {
        double xForce = 0;
        double yForce = 0;
        for (int j = 0; j < planets; j++) {
            if (i != j) {
            double xDelta = (pCB[i]->getxPostion() - pCB[j]->getxPostion());
            double yDelta = (pCB[i]->getyPostion() - pCB[j]->getyPostion());
            double r = sqrt(pow(xDelta, 2)+pow(yDelta, 2));
            double force = (gravity * (pCB[i]->getMass()) * (pCB[j]->getMass()))/pow(r,2); //NOLINT
            xForce += force * (xDelta/r);
            yForce += force * (yDelta/r);
            }
        }
        double xAcceleration = (xForce/pCB[i]->getMass());
        double yAcceleration = (yForce/pCB[i]->getMass());
        double xVelocity = (pCB[i]->getxVelocity()+ time * xAcceleration);
        double yVelocity = (pCB[i]->getyVelocity()+ time * yAcceleration);
        pCB[i]->setxVelocity(xVelocity);
        pCB[i]->setyVelocity(yVelocity);
    }
    for (int k = 0; k < planets; k++) {
        double xPostion = (pCB[k]->getxPostion() + time * pCB[k]->getxVelocity()); //NOLINT
        double yPostion = (pCB[k]->getyPostion() + time * pCB[k]->getyVelocity()); //NOLINT
        pCB[k]->setxPostiton(xPostion);
        pCB[k]->setyPostiton(yPostion);
        std::cout << " this is " << k << " " << pCB[k]->getxPostion() << " " << pCB[k]->getyPostion() << " " << pCB[k]->getxVelocity() << " " << pCB[k]->getyVelocity() << " " << pCB[k]->getMass() << " " << pCB[k]->getFileName() << "\n"; //NOLINT
        pCB[k]->setPos();
    }
}
