#include "Song.h"
#include "Library.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/** Song Constructor - Constructs a song with passed in string parameters.
@param titla - title from file.
@param strista - artist from file.
@param albuma - album from file.
@param yeara - year form file (string). */
Song::Song(std::string titlea, std::string artista, std::string albuma, std::string yeara)  {

    title  = titlea;
    artist = artista;
    album  = albuma;
    std::istringstream ss(yeara);
    ss >> year;

}//end song constructor

/** Song Constructor - Constructs songs with passid in string / int parameters.
@param titlea - title from user.
@param artista - artist from user.
@param albuma - album from user.
@param yeara - year from user (int). */
Song::Song(std::string titlea, std::string artista, std::string albuma, int yeara)  {

    title  = titlea;
    artist = artista;
    album  = albuma;
    year   = yeara;

}//end song constructor

/** Default Song Constructor. */
Song::Song()  {

    title  = "";
    artist = "";
    album  = "";
    year   =  0;

}//end song


/** Overloaded output operator; enables a formatted output for
    Fraction objects.
    @param mySong - explicit parameter.
    @return out - the io stream with the desired output. */
std::ostream & operator<< (std::ostream & out, Song mySong)  {

    out << mySong.getTitle()  <<  ","
        << mySong.getArtist() <<  ","
        << mySong.getAlbum()  <<  ","
        << mySong.getYear()   << std::endl;

    return out;

}//end ostream

/** Overloaded input operator; allows user inputs to be assigned
    to specific class traits in one call.
    @param mySong - explicit parameter.
    @return in - the input stream with the user's values. */
std::istream & operator>> (std::istream & in, Song & mySong)  {

    std::string title;
    std::string artist;
    std::string album;
    int year;

    std::cout << "\nPlease enter a title : ";
    std::cin.ignore();
    getline(std::cin, title);
    std::cin.clear();

    std::cout << "Please enter an artist : ";
    getline(std::cin, artist);
    std::cin.clear();

    std::cout << "Please enter an album : ";
    getline(std::cin, album);
    std::cin.clear();

    bool gotInt = false;
    while (!gotInt) {
        std::cout << "Please enter a year : ";
        if (std::cin >> year) {
            gotInt = true;
        }//end if
        else {
            std::cin.clear();
            std::string invalid;
            std::cin >> invalid;
            std::cout << "Invalid entry, please enter an integer.\n" << std::endl;
        }//end else
    }//end while

    mySong.title  = title;
    mySong.album  = album;
    mySong.artist = artist;
    mySong.year   = year;

    return in;

}//end instream

/** Overloaded Less Than Operator
@param song - implicit song parameter.
@return bool - true or false. */
bool Song::operator<  (const Song & song)  {

    if (artist < song.artist)  {
        return true;
    }//end if
    else if (artist == song.artist) {
        if (title < song.title)  {
            return true;
        }//end if
    }//end else if
    else  {
        return false;
    }//end else

}//end operator<

/** Overloaded Greater Than Operator
@param song - song object.
@return bool - true or false. */
bool Song::operator>  (const Song & song)  {

    if (artist > song.artist)  {
        return true;
    }//end if
    else if (artist == song.artist) {
        if (title > song.title)  {
            return true;
        }//end if
    }//end else if
    else  {
        return false;
    }//end else

}//end operator>

/** Overloaded Equivalence Operator
@param song - song object.
@return bool - true or false. */
bool Song::operator== (const Song & song)  {

    if (title  == song.title  &&
        artist == song.artist &&
        album  == song.album  &&
        year   == song.year   ){
        return true;  }
    else {
        return false; }

}//end operator==

/** Get Title
@return title - the song's title. */
std::string Song::getTitle()  {
    return title;
}//end getTitle

/** Get Artist
@return artist - the song's artist. */
std::string Song::getArtist()  {
    return artist;
}//end getArtist

/** Get Album
@return album - the songs album. */
std::string Song::getAlbum()  {
    return album;
}//end getAlbum

/** Get Year
@return year - the year the song came out. */
int Song::getYear()  {
    return year;
}//end getYear
