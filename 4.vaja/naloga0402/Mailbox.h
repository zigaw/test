//
// Created by weing on 20/03/2023.
//

#ifndef NALOGA0402_MAILBOX_H
#define NALOGA0402_MAILBOX_H

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Message.h"
#include "User.h"
#include "Priority.h"
#include "DateTime.h"



class Mailbox {
private:
    std::vector<Message> messages;
public:
    Mailbox();

    void addMessage(Message message);

    std::string toString();

    std::vector<Message> returnMessages() const;
};


#endif //NALOGA0402_MAILBOX_H
