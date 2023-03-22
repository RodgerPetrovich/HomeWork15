#include "chat.h"
#include "iostream"
#include <string>

Chat::Chat() {
  
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = nullptr;
    }
    data_count = 0;
}
int Chat::hashLogin(string _login)
{
    int ha = 0;
    for (int i = 0; i < _login.size(); i++)
    {
        ha += _login[i];
    }
    
    return ha % SIZE;
}
void Chat::reg(string _login, string pass) {
    uint* x = sha1(pass);
    AuthData* newUser = new AuthData(_login,x);
    if (!data[hashLogin(_login)])
        data[hashLogin(_login)] = newUser;
    else
    {
        
        AuthData* curent = data[hashLogin(_login)];
        while (curent->next)
        {
            curent = curent->next;
        }
        curent->next = newUser;
        

    }
    data_count++;
    cout << "login - " << _login << " registered in slot "<< hashLogin(_login)<<" with passhash - " << *x << endl;
}
bool Chat::login(string _login, string pass) {
    
   // int ha = hashLogin(_login);
    AuthData* curent = data[hashLogin(_login)];
    while (curent)
    {
        if (curent->login == _login) {
            
            break;
        }
        curent = curent->next;
    }
    if (!curent)
    {
        cout << "no login - " << _login << " in base " << endl;
        return false;
    }

    uint* digest = sha1(pass);

    bool cmpHashes = !memcmp(
        curent->pass_sha1_hash,
        digest,
        SHA1HASHLENGTHBYTES);
    delete[] digest;
    if (cmpHashes)cout << "Login - " << _login << " enter!" << endl;
    else cout << "Login - " << _login << " password fail!" << endl;
    return cmpHashes;
}