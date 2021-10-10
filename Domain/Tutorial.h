//
// Created by mitza on 19-Mar-21.
//

#ifndef A45_MITZA23_TUTORIAL_H
#define A45_MITZA23_TUTORIAL_H

#include <string>


/**
 * Tutorial class represents a tutorial inside the database/watchlist of the user
 * title: the title of the tutorial - std::string
 * presenter: the presenter of the tutorial - std::string
 * minutes: length in minutes of the tutorial - int
 * seconds: length in seconds of the tutorial - int
 * link: the link of the tutorial - std::string
 */

class Tutorial {
private:
    std::string title;
    std::string presenter;
    int minutes;
    int seconds;
    int likes;
    std::string link;

public:
    /// Tutorial class represents a tutorial inside the database/watchlist of the user
    /// \param title the title of the tutorial - std::string
    /// \param presenter the presenter of the tutorial - std::string
    /// \param minutes length in minutes of the tutorial - int
    /// \param seconds length in seconds of the tutorial - int
    /// \param likes number of likes of the tutorial - int
    /// \param link the link of the tutorial - std::string
    Tutorial(const std::string &title, const std::string &presenter, int minutes, int seconds, int likes,
             const std::string &link);

    Tutorial();

    Tutorial(const Tutorial&) = default;
    Tutorial& operator=(const Tutorial&) = default;

    int getMinutes() const;

    void setMinutes(int minutes);

    int getSeconds() const;

    void setSeconds(int seconds);

    int getLikes() const;

    void setLikes(int likes);

    const std::string &getTitle() const;

    void setTitle(const std::string title);

    const std::string &getPresenter() const;

    void setPresenter(const std::string &presenter);

    const std::string &getLink() const;

    void setLink(const std::string &link);

    /// Gets the string representation of the tutorial
    /// \return representation of the tutorial - std::string
    std::string toString();

    bool operator==(const Tutorial &rhs) const;

    ///Plays the link of the tutorial in Chrome
    void play();

    friend std::istream & operator >> (std::istream &in, Tutorial& t);

    friend std::ostream & operator << (std::ostream &out, const Tutorial &t);

    std::string toHTML();

    std::string toCSV();
};


#endif //A45_MITZA23_TUTORIAL_H
