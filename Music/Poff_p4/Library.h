#ifndef LIBRARY_H
#define LIBRARY_H
#include <Song.h>
#include <vector>

class Library  {

    public:

        /** Library Constructor
        @param fileName - name of the file to be read off of. */
        Library(std::string fileName);
        /** Write to File - Allows the user to write to the file.
        @param fileName - the name of the file. */
        void writeToFile(std::string fileName);

        /** Search Title - Lets the user search by titles.
        @param title - title the user wants to find.
        @param libObj - Library object. */
        void searchTitle(std::string title, Library libObj);
        /** Search Artists - Lets the user search by artist.
        @param artist - the artist the user wants to find.
        @param libObj - library object. */
        void searchArtist(std::string artist, Library libObj);
        /** Search Album - Lets the user search by album.
        @param album - album the user wants to search by.
        @param libObj - Library object. */
        void searchAlbum(std::string album, Library libObj);
        /** Search Year - Lets the user search by year.
        @param decade - the decade the user is looking for.
        @param libObj - Library object. */
        void searchYear(int year, Library libObj);

        /** Add Song To Library - Lets the user add a song to the library.
        @param newSong - song the user wants to add. */
        void addSongLib(Song newSong);
        /** Remove Song From Library - Lets the user remove a song from the library.
        @param index - the index the user wants to remove. */
        void removeSongLib(int index);
        /** Remove By Title - Lets the user remove a song by title.
        @param silly - it's a silly string. */
        void removeByTitle(std::string silly);

        /** Print Vector Unsorted - Prints out the vector unsorted. */
        void printVectorNotSorted();
        /** Print Vector - Sorts, then prints, the song vector. */
        void printVector();

        /** Get Size - Returns the size of the song vector. */
        int getSize();

    private:

        std::vector<Song> songVec;

};

#endif // LIBRARY_H
