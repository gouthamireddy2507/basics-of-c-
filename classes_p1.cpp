#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class FlameBookUser {
    private:
    string first_name;
    string last_name;
    FlameBookUser *friends[10];
    int no_of_friends;

    public:
    string get_first_name() {
      return first_name;
    }

    string get_last_name() {
      return last_name;
    }

    FlameBookUser** get_friends() {
      return friends;
    }

    int get_no_of_friends() {
      return no_of_friends;
    }
    FlameBookUser(string, string);
    void print_details();
    void add_friend(FlameBookUser user);
};

FlameBookUser::FlameBookUser(string first_name, string last_name) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->no_of_friends = 0;
}

void FlameBookUser::print_details(){
    cout<<"First Name ==  "<<first_name<<endl;
    cout<<"Last Name == "<<last_name<<endl;
    cout<<"Friends List "<<endl;

    for(int i=0;i<no_of_friends;i++){
        FlameBookUser user = *(friends[i]);
        cout<<"First Name ==  "<<user.first_name<<endl;
        cout<<"Last Name == "<<user.last_name<<endl;
    }

}

void FlameBookUser::add_friend(FlameBookUser user){
    friends[no_of_friends] = &user;
    no_of_friends++;
}

void mutual_friends(FlameBookUser user1, FlameBookUser user2) {
    cout<<"Mutal Friends between "<<user1.get_first_name() <<" "<< user1.get_last_name() <<" and " <<user2.get_first_name() << " "<<user2.get_last_name() <<endl;

    for(int i=0;i<user1.get_no_of_friends();i++){
        for(int j=0;j<user2.get_no_of_friends();j++){
            FlameBookUser** user1_friends = user1.get_friends();
            FlameBookUser** user2_friends = user2.get_friends();
            if(user1_friends[i]->get_first_name() == user2_friends[j]->get_first_name() && user1_friends[i]->get_last_name() == user2_friends[j]->get_last_name() )
                cout<<user1_friends[i]->get_first_name()<< "  "<<user1_friends[i]->get_last_name();
        }
    }
}
// int main() {
//     FlameBookUser user1("Bill", "Gates");
//     FlameBookUser user2("Mark", "Zuckerberg");
//     FlameBookUser user3("Larry","Page");

//     user1.add_friend(user2);
//     user1.add_friend(user3);
//     user1.print_details();

//     user2.add_friend(user3);

//     mutual_friends(user1,user2);
// }