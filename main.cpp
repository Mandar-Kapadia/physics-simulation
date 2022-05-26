/*Copyright 2022  Mandar Kapadia */
#include "Universe.h"//NOLINT
int main(int argc, char* argv[]) {
     sf::Image input;
     if (!input.loadFromFile("starfield.jpg")) {
        std::cout << "could not load enemy texture";
        return 0;
      }

      sf::Font font;
      font.loadFromFile("Arial.ttf");

      sf::Text timeText;
      timeText.setFont(font);
      timeText.setCharacterSize(14);


     double t = atol(argv[1]);
     double sec = atol(argv[2]);

     sf::Music music;
     if (!music.openFromFile("Rocky_theme_song.wav")) {
       return(-1);
     }
     music.setLoop(1);
     music.play();

     sf::RenderWindow window(sf::VideoMode(static_cast<int>(input.getSize().x),static_cast<int>(input.getSize().y)), "universe"); //NOLINT
     sf::Texture textureInput;
     textureInput.loadFromImage(input);

     sf::Sprite spriteInput;
     spriteInput.setTexture(textureInput);

     Universe uni(static_cast<int>(input.getSize().x),static_cast<int>(input.getSize().y)); //NOLINT
     std::cin >> uni;

     window.setFramerateLimit(60);
    int i = 0;
    while (window.isOpen()) {
      if(i<t){
        uni.step(sec); 
        std::cout<<"\n";
        i += sec;   
      }
      timeText.setString("Time: " + std::to_string(i));

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(spriteInput);
        window.draw(timeText);
        window.draw(uni);
        window.display();
    }
    return 0;
}
