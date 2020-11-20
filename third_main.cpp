#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

/*Public parameters*/
// Main window where it is displayed the screen
//sf::RenderWindow mainWindow(sf::VideoMode(800,600), "SimplePong Game", sf::Style::Close | sf::Style::Titlebar);
// Event object
sf::Event mainEvent;
bool up = false;
bool down = false;
bool left = false;
bool right = false;

/* Variables */
int speed = 0;
int status;

/*game part functions*/
void eventPart();
void logicPart();

int main() {
    std::cout<<"Robot started! You can handle it with arrow keys, enjoy!"<<std::endl;
    /* Main Game Loop */
    while(1){
        /* Event part */
        eventPart();
        logicPart();
    }
}

/* Events part */
void eventPart(){
    while(1){
        /* Pressed */
        if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Up) up = true;
        if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Down) down = true;
        if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Left) left = true;
        if(mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Right) right = true;
        /* Released */
        if(mainEvent.type == sf::Event::KeyReleased && mainEvent.key.code == sf::Keyboard::Up) up = false;
        if(mainEvent.type == sf::Event::KeyReleased && mainEvent.key.code == sf::Keyboard::Down) down = false;
        if(mainEvent.type == sf::Event::KeyReleased && mainEvent.key.code == sf::Keyboard::Left) left = false;
        if(mainEvent.type == sf::Event::KeyReleased && mainEvent.key.code == sf::Keyboard::Right) right = false;
    }
}

/* Logic part */
void logicPart(){
    if(up){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/forward.py&");
    }
    if(down){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/backward.py&");
    }
    if(left){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/left.py&");
    }
    if(right){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/right.py&");
    }
}