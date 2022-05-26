/*Copyright 2022  Mandar Kapadia */
#include <SFML/System.hpp> //NOLINT
#include <SFML/Window.hpp>//NOLINT
#include <SFML/Graphics.hpp>//NOLINT
#include <SFML/Audio.hpp>//NOLINT
#include<iostream>//NOLINT
#include<string>//NOLINT
#include<memory>//NOLINT
#include<vector>//NOLINT
#include<math.h>//NOLINT
#include<stdlib.h>//NOLINT
class CelestialBody:public sf::Drawable{
 public:
        CelestialBody(double _xPostion, double _yPostion, double _xVelocity, double _yVelocity, double _mass, std::string _filename, double xViewPoint, double yViewPoint, double uRadius);//NOLINT
        void setxPostiton(const double xPosition);
        void setyPostiton(const double yPosition);
        void setxVelocity(const double xVelocity);
        void setyVelocity(const double yVelocity);
        void setMass(const double mass);
        void setxForce(const double xForce);
        void setyForce(const double xForce);

        double getxPostion()const;
        double getyPostion()const;
        double getyVelocity()const;
        double getxVelocity()const;
        double getMass()const;
        double getxForce()const;
        double getyForce()const;
        sf::Sprite getSprite()const;
        std::string getFileName()const;
        friend std::istream& operator >> (std::istream &is,  CelestialBody &temp);//NOLINT
        void setPos();

 private:
        double xPosition;
        double yPosition;
        double xVelocity;
        double yVelocity;
        double mass;

        double xViewPoint;
        double yViewPoint;

        double uRadius;

        double xForce = 0;
        double yForce = 0;

        sf::Sprite sprite;
        sf::Texture texture;
        std::string filename;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //NOLINT
};
