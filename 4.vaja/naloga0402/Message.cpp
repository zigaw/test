#include "Message.h"


Message::Message(User *sender, User *reciever, const DateTime &recieved, const std::string &title,
                 const std::string &content, Priority priority) : recieved(recieved) {
    this->sender = sender;
    this->title = title;
    this->content = content;
    this->priority = priority;
    this->recievers.push_back(reciever);
}


std::string Message::toString() {
    std::stringstream messageString;
    messageString << "Sender: " << sender->toString() << std::endl;
    messageString << "Recievers:";
    for (int i = 0; i < recievers.size(); ++i) {
        messageString << recievers[i]->toString() << ", ";
    }
    messageString << std::endl;
    messageString << "Recieved: " << recieved.toString() << std::endl;
    messageString << "Title: " << title << std::endl;
    messageString << "Content: " << content << std::endl;
    messageString << "Priority:" << enumToString(priority) << std::endl;
    return messageString.str();
}

void Message::setContent(std::string setContent) {
    this->content = setContent;
}

void Message::setTitle(std::string setTitle) {
    this->title = setTitle;
}

std::string Message::getContent() {
    return this->content;
}

std::string Message::getTitle() {
    return this->title;
}


void Message::addReceiever(User *user) {
    this->recievers.push_back(user);
}

std::string Message::enumToString(Priority priority) const {
    switch (priority) {
        case Priority::Low:
            return "Low";
        case Priority::Normal:
            return "Normal";
        case Priority::Critical:
            return "Critical";
    }
}