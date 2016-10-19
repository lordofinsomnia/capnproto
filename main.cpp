#include "addressbook.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>
#include <capnp/schema.h>
#include <capnp/dynamic.h>

using ::capnp::DynamicValue;
using ::capnp::DynamicStruct;
using ::capnp::DynamicEnum;
using ::capnp::DynamicList;
using ::capnp::List;
using ::capnp::Schema;
using ::capnp::StructSchema;
using ::capnp::EnumSchema;

using ::capnp::Void;
using ::capnp::Text;
using ::capnp::MallocMessageBuilder;
using ::capnp::PackedFdMessageReader;

using namespace std;
using addressbook::Person;
using addressbook::AddressBook;

const int ADDRESS_BOOK_SIZE = 2;
int main(int argc, char *argv[])
{    


    ::capnp::MallocMessageBuilder message;
    AddressBook::Builder addressBook = message.initRoot<AddressBook>();
    capnp::List<Person>::Builder people = addressBook.initPeople(ADDRESS_BOOK_SIZE);

    int i;
    for(i=0;i<ADDRESS_BOOK_SIZE;i++){
        Person::Builder person = people[i];
        string name("test"+std::to_string(i));
        string mail(name+"@test.com");
        person.setName(name);
        person.setEmail(mail);
        person.setId(i);
    }

    return 0;
}
