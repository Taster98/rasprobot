#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

/*Public parameters*/
// Main window where it is displayed the screen
sf::RenderWindow mainWindow(sf::VideoMode(400,200), "SimplePong Game", sf::Style::Close | sf::Style::Titlebar);
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
void initWindow();
void eventPart();
void logicPart();

int main() {
    /*Window creation and settings*/
    initWindow();
    std::cout<<"Robot started! You can handle it with arrow keys, enjoy!"<<std::endl;
    /* Main Game Loop */
    while(mainWindow.isOpen()){
        /* Event part */
        eventPart();
        logicPart();
        mainWindow.display();
    }
}

/* Window initialization */
void initWindow(){
    std::cout << "Game started" << std::endl;
}

/* Events part */
void eventPart(){
    while(mainWindow.pollEvent(mainEvent)){
        if(mainEvent.type == sf::Event::Closed) mainWindow.close();
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
    }else if(down){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/backward.py&");
    }else if(left){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/left.py&");
    }else if(right){
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
        //avvio il comando avanti
        status = system("python3 movements/right.py&");
    }else if(!right && !left && !up && !down){
        //SE NESSUN TASTO È PREMUTO ALLORA FERMO TUTTO
        //pausa gli altri comandi
        status=system("python3 movements/pause.py");
        //uccido gli altri comandi
        status=system("sudo killall python3");
    }
}