#pragma once

#include "sha1.h"
#include <string>

#define SIZE 10


class Chat {
public:
    Chat();
    ~Chat();
    int hashLogin(string _login,int i);
    void reg(string _login, string pass);
    void reg(string _login, uint* ph);
    bool login(string _login, string pass);
    void resize();
    void showUsers();
    void deleteUser(string _login);

private:
    enum userSlotStatus
    {
        free, // свободен
        engaged, //занят
        deleted //удален
    };
    struct AuthData {
        AuthData() :
            login(""),
            pass_sha1_hash(0),
            status(userSlotStatus::free){}
       
     
        AuthData(string _login, uint* sh1) {
            login = _login;
            pass_sha1_hash = sh1;
            status = userSlotStatus::engaged;
        }
        AuthData& operator = (const AuthData& other) {
            this->login = other.login;
            this->pass_sha1_hash = other.pass_sha1_hash;
            this->status = other.status;

            return *this;
        }
        string login;
        uint* pass_sha1_hash;
        userSlotStatus status;
       
    };
    AuthData* data;
    int memSize;
    int data_count;
};