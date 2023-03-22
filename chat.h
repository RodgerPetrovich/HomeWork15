#pragma once

#include "sha1.h"
#include <string>

#define SIZE 10


class Chat {
public:
    Chat();
    int hashLogin(string _login);
    void reg(string _login, string pass);
    bool login(string _login, string pass);

private:
    struct AuthData {
        AuthData() :
            login(""),
            pass_sha1_hash(0),next(nullptr) {
        }
        ~AuthData() {
            if (pass_sha1_hash != 0)
                delete[] pass_sha1_hash;
        }
        AuthData(string _login, uint* sh1) {
            login = _login;
            pass_sha1_hash = sh1;
            next = nullptr;
        }
        AuthData& operator = (const AuthData& other) {
            this->login = other.login;

            if (pass_sha1_hash != 0)
                delete[] pass_sha1_hash;
            pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];

            memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);

            return *this;
        }
        string login;
        uint* pass_sha1_hash;
        AuthData* next;
    };
    AuthData* data[SIZE];

    int data_count;
};