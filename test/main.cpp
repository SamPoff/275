#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main()  {

    std::vector<std::string> title, artist, album, year;

    std::string input, titlea, artista, albuma, yeara;
    std::ifstream file ("songs.txt");

    while (std::getline(file, input))  {

        std::stringstream linestream(input);

        std::getline(linestream, titlea , ',');
        std::getline(linestream, artista, ',');
        std::getline(linestream, albuma , ',');
        std::getline(linestream, yeara  , ',');

        title.push_back(titlea);
        artist.push_back(artista);
        album.push_back(albuma);
        year.push_back(yeara);

    }//end while

    for (int i = 0; i < year.size(); i++)  {
        Song mySong = Song(title[i], artist[i], album[i], year[i]);
        songVec.push_back(mySong);
    }//end for

    for (int i = 0; i < mySong.size(); i++)  {
        std::cout << mySong[i] << endl;
    }//end for

}//end main
