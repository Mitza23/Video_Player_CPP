//
// Created by mitza on 21-Mar-21.
//

#ifndef A45_MITZA23_REPOSITORY_H
#define A45_MITZA23_REPOSITORY_H


#include <Tutorial.h>
#include <string>
#include <vector>
#include "../Exceptions/Exception.h"
#include "../Exceptions/RepositoryException.h"

/**
 * Repository class represents a wrap around the std::vector on Tutorial
 * list: list of Tutorial - std::vector<Tutorial>
 */

class Repository {
protected:
    std::vector<Tutorial> list;

public:
    Repository();


    std::vector<Tutorial> & getList();

    /// Finds the position of a tutorial inside the repo
    /// \param title the title of the tutorial to be searched - std::string
    /// \return the position of the tutorial - int
    int findTutorialPosition(std::string title);

    /// Finds a tutorial inside the repo
    /// \param title the title of the tutorial to be searched - std::string
    /// \raise Exception in case the tutorial hasn't been found
    /// \return the tutorial - Tutorial&
    Tutorial& findTutorial(std::string title);

    bool existsTutorial(std::string title);

    /// Adds a tutorial to the repo
    /// \param t the tutorial to be added - Tutorial&
    /// \raise RepositoryException if a tutorial with the same name already exists
    void addTutorial(Tutorial& t);

    /// Deletes a tutorial from the repo
    /// \param title the title of the tutorial to be deleted - std::string
    /// \raise RepositoryException if the tutorial to be deleted doesn't exist
    void deleteTutorial(std::string title);

    /// Updates the title of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newTitle the new title - std::string
    /// \raise RepositoryException in case the tutorial doesn't exist or there is another with the same name
    void updateTutorialTitle(std::string title, std::string newTitle);

    /// Updates the title of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newPresenter the new presenter - std::string
    /// \raise RepositoryException in case the tutorial doesn't exist
    void updateTutorialPresenter(std::string title, std::string newPresenter);

    /// Updates the minutes duration of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newValue the new minutes duration - int
    /// \raise RepositoryException in case the tutorial doesn't exist
    void updateTutorialMinutes(std::string title, int newValue);

    /// Updates the seconds duration of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newValue the new seconds duration - int
    /// \raise RepositoryException in case the tutorial doesn't exist
    void updateTutorialSeconds(std::string title, int newValue);

    /// Updates the number of likes of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newValue the new number of likes - int
    /// \raise RepositoryException in case the tutorial doesn't exist
    void updateTutorialLikes(std::string title, int newValue);

    /// Updates the link of a specified tutorial
    /// \param title the title of the tutorial to be updated - std::string
    /// \param newLink the new link - std::string
    /// \raise RepositoryException in case the tutorial doesn't exist
    void updateTutorialLink(std::string title, std::string newLink);

    /// Gets the string representation of the tutorials in the repository
    /// \return representation of the tutorials in the repository - std::string
    std::string toString();

    virtual void saveToFile();
};


#endif //A45_MITZA23_REPOSITORY_H
