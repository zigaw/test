#ifndef NALOGA0402_MESSAGE_H
#define NALOGA0402_MESSAGE_H

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Priority.h"
#include "User.h"
#include "DateTime.h"



class Message {
private:
    User *sender;
    std::vector<User*> recievers;
    DateTime recieved;
    std::string title;
    std::string content;
    Priority priority;
public:
    Message(User *sender, User *reciever, const DateTime &recieved, const std::string &title,
            const std::string &content, Priority priority);

    void addReceiever(User *user);

    std::string toString();

    void setTitle(std::string setTitle);

    void setContent(std::string setContent);

    std::string getTitle();

    std::string getContent();

    std::string enumToString(Priority priority) const;


};


#endif //NALOGA0402_MESSAGE_H
