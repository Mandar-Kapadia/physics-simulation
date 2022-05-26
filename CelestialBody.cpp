/*Copyright 2022  Mandar Kapadia */
#include "CelestialBody.h"
CelestialBody::CelestialBody(double _xPostion, double _yPostion, double _xVelocity, double _yVelocity, double _mass, std::string _filename, double _xViewPoint, double _yViewPoint, double _uRadius) { //NOLINT
    this->xPosition = _xPostion;
    this->yPosition = _yPostion;
    this->xVelocity = _xVelocity;
    this->yVelocity = _yVelocity;
    this->mass = _mass;
    this->filename = _filename;

    this->texture.loadFromFile(this->filename);
    this->sprite.setTexture(this->texture);
    this->xViewPoint = _xViewPoint;
    this->yViewPoint = _yViewPoint;
    this->uRadius = _uRadius;
    setPos();
}
sf::Sprite CelestialBody::getSprite()const {
    return(this->sprite);
}
double CelestialBody::getMass()const {
    return (this->mass);
}
double CelestialBody::getxPostion()const {
    return(this->xPosition);
}
double CelestialBody::getyPostion()const {
    return(this->yPosition);
}
double CelestialBody::getxVelocity()const {
    return(this->xVelocity);
}
double CelestialBody::getyVelocity()const {
    return(this->yVelocity);
}

double CelestialBody::getyForce()const {
    return(this->yForce);
}
double CelestialBody::getxForce()const {
    return(this->xForce);
}
std::string CelestialBody::getFileName()const {
    return(this->filename);
}
void CelestialBody::setxPostiton(const double xPosition) {
    this->xPosition = xPosition;
}
void CelestialBody::setyPostiton(const double yPosition) {
    this->yPosition = yPosition;
}
void CelestialBody::setxVelocity(const double xVelocity) {
    this->xVelocity = xVelocity;
}
void CelestialBody::setyVelocity(const double yVelocity) {
    this->yVelocity = yVelocity;
}
void CelestialBody::setMass(const double mass) {
    this->mass = mass;
}
void CelestialBody::setxForce(const double xForce) {
    this->xForce = xForce;
}
void CelestialBody::setyForce(const double yForce) {
    this->yForce = yForce;
}
std::istream& operator >> (std::istream &is,  CelestialBody &temp) {
    is >> temp.xPosition >> temp.yPosition >> temp.xPosition >> temp.xVelocity >> temp.yVelocity >> temp.mass >> temp.filename;//NOLINT
    temp.texture.loadFromFile(temp.filename);
    temp.sprite.setTexture(temp.texture);
    return is;
}
  void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const { //NOLINT 
    target.draw(sprite, states);
}
void CelestialBody::setPos() {
    double scaleXpostion = ((xPosition/uRadius)*(xViewPoint/2)+(xViewPoint/2)-((texture.getSize().x)/2)); //NOLINT
    double scaleYpostion = ((-yPosition/uRadius)*(yViewPoint/2)+(yViewPoint/2)-((texture.getSize().y)/2)); //NOLINT
    sprite.setPosition(scaleXpostion, scaleYpostion);
}
