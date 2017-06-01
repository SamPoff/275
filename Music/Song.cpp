#include "Song.h"
#include "Library.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Song::Song()  {

    std::string title  = "default";
    std::string artist = "default";
    std::string album  = "default";
    int year = -1;

}//end song default constructor

Song::Song(std::string titlea, std::string artista, std::string albuma, std::string yeara)  {

    std::string title  = titlea;
    std::string artist = artista;
    std::string album  = albuma;
    int year = std::stoi(yeara);

}//end song constructor

Song &operator< ()  {


}//end overload<

Song &operator> ()  {


}//end overload>

Song &operator== ()  {


}//end overload==
