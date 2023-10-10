#include "Mailbox.h"
#include "Message.h"
#include "User.h"
#include "Time.h"
#include "DateTime.h"
#include "Priority.h"


using namespace std;


int main() {

    User *user1 = new User("", "", "");
    user1->setFirstName("Chris");
    user1->setLastName("Bumstead");
    user1->setAddress("Goaposvedska");


    User *user2 = new User("Arnold", "Schwarzeneger", "Smetanova");
    User *user3 = new User("Ronie", "Coleman", "Mladinska");
    DateTime dateTime1(Date(12, 11, 2022), Time(11, 30, 0));

    Message message1(user1, user2, dateTime1, "", "", Critical);
    message1.setTitle("Olimpia");
    message1.addReceiever(user3);
    message1.setContent("Pozdravljeni, gospod Arnold...");
    Mailbox mailbox1;
    mailbox1.addMessage(message1);

    cout << user1->getFirstName() << endl;
    cout << user1->getLastName() << endl;
    cout << user1->getAddress() << endl;
    cout << message1.getTitle() << endl;
    cout << message1.getContent() << endl;


    delete user1;
    delete user2;
    delete user3;


    return 0;
}