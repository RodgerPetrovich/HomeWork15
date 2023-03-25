#include "chat.h"
#include "iostream"
#include <string>

Chat::Chat() {
  
    data_count = 0;
    memSize = SIZE;
    data = new AuthData[memSize];
   
}
Chat::~Chat()
{
    delete[] data;
}
int Chat::hashLogin(string _login, int i)
{
    int sum = 0;
    for (int i = 0; i < _login.size(); i++)
    {
        sum += _login[i];
    }
       
    return (sum % memSize + i * i) % memSize;
}

void Chat::deleteUser(string _login)
{
    int index = -1;
    for (int i = 0; i < memSize; i++)
    {
        index = hashLogin(_login, i);
        if (data[index].status == userSlotStatus::engaged && data[index].login == _login)
        {
            data[index].login = "";
            data[index].pass_sha1_hash = 0;
            data[index].status = userSlotStatus::deleted;
            cout << "user " << _login << " is deleted" << endl;
            data_count--;
            return;
            }
    }
    cout << "user " << _login << " not find" << endl;
}

void Chat::resize()
{
    AuthData* newData = data;
   
    int oldMem = memSize;
    memSize *= 2;
    data = new AuthData[memSize];
    data_count = 0;
    
    for (int i = 0; i < oldMem; i++)
    {
        if (newData[i].status == userSlotStatus::engaged)
        {
            reg(newData[i].login, newData[i].pass_sha1_hash);
        }
    }
    
}

void Chat::reg(string _login, string pass) {
    uint* passHash = sha1(pass);
    int index = -1, i = 0;

   

    for (; i < memSize; i++)
    {
        index = hashLogin(_login, i);
        if (data[index].status == userSlotStatus::engaged && data[index].login == _login)
        {
            cout << "login "<< _login<<" is busy" << endl;
            return;
        }
        if (data[index].status != userSlotStatus::engaged)
        {
            break;
        }
    }
  
        if (i >= memSize)
        {
            resize();
            cout << "ARRAY RESIZED" << endl;
            reg(_login, pass);
            return;
        }
        data[index] = AuthData(_login, passHash);
        cout << "user " << _login << " add to chat" << endl;
       
    data_count++;
    
}

void Chat::showUsers()
{
    for (int i = 0; i < memSize; i++)
    {
        if (data[i].status == userSlotStatus::engaged)
            cout << "login - " << data[i].login << ", num in array - " << i << ", passHash - " << data[i].pass_sha1_hash << endl;
    }
}

void Chat::reg(string _login, uint* ph) {
    uint* passHash = ph;
    int index = -1, i = 0;
    for (; i < memSize; i++)
    {
        index = hashLogin(_login, i);
        if (data[index].status != userSlotStatus::engaged)
        {
            break;
        }
    }

    if (i > memSize)
    {
        return;
    }
    data[index] = AuthData(_login, passHash);
   
    data_count++;

}

bool Chat::login(string _login, string pass) {
    
    int index = -1, i = 0;
    uint* passHash = sha1(pass);
    for (i; i < memSize; i++)
    {
        index = hashLogin(_login, i);
        if (data[index].login == _login && data[index].pass_sha1_hash == passHash)
            return true;
    }
    return false;
    
}