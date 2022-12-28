// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-28
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_SOUND_H
#define PROJEKT_SOUND_H

#include <SFML/Audio.hpp>

#include <string>

class Sound: public sf::Sound
{
public:
    Sound(std::string path);

private:
    sf::SoundBuffer buffer;

};


#endif //PROJEKT_SOUND_H
