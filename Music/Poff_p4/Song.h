#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song  {

    public:

        /** Song Constructor - Constructs a song with passed in string parameters.
        @param titla - title from file.
        @param strista - artist from file.
        @param albuma - album from file.
        @param yeara - year form file (string). */
        Song(std::string titlea, std::string artista, std::string albuma, std::string yeara);
        /** Song Constructor - Constructs songs with passid in string / int parameters.
        @param titlea - title from user.
        @param artista - artist from user.
        @param albuma - album from user.
        @param yeara - year from user (int). */
        Song(std::string titlea, std::string artista, std::string albuma, int yeara);
        /** Default Song Constructor. */
        Song();

        /** Overloaded output operator; enables a formatted output for
        Fraction objects.
        @return out - the io stream with the desired output. */
        friend std::ostream & operator<< (std::ostream & out, Song mySong);
        /** Overloaded input operator; allows user inputs to be assigned
        to specific class traits in one call.
        @return in - the input stream with the user's values. */
        friend std::istream  &operator>> (std::istream &in, Song & mySong);
        /** Overloaded Less Than Operator
        @param song - implicit song parameter.
        @return bool - true or false. */
        bool operator<  (const Song & song);
        /** Overloaded Greater Than Operator
        @param song - song object.
        @return bool - true or false. */
        bool operator>  (const Song & song);
        /** Overloaded Equivalence Operator
        @param song - song object.
        @return bool - true or false. */
        bool operator== (const Song &song);

        /** Get Title
        @return title - the song's title. */
        std::string getTitle();
        /** Get Artist
        @return artist - the song's artist. */
        std::string getArtist();
        /** Get Album
        @return album - the songs album. */
        std::string getAlbum();
        /** Get Year
        @return year - the year the song came out. */
        int         getYear();

    private:

        std::string title;
        std::string artist;
        std::string album;
        int year;

};

#endif // SONG_H
