#include "Mailbox.h"

Mailbox::Mailbox() : messages() {}


std::vector<Message> Mailbox::returnMessages() const {
    return this->messages;
}

void Mailbox::addMessage(Message message) {
    this->messages.push_back(message);
}


std::string Mailbox::toString() {
    std::stringstream mailBoxString;
    mailBoxString << "Mailbox: ";
    for (int i = 0; i < messages.size(); i++) {
        mailBoxString << messages[i].toString() << ", ";

    }
    return mailBoxString.str();
}