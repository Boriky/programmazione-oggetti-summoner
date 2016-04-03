#ifndef USER_H
#define USER_H

#include <QString>

class Login;

class Profile;

// AVATARS?

// IDENTIFIES A REGISTERED USER
class User {
public:
    User(Login* =0, Profile* =0, bool = false);
    virtual ~User() {}
    Login* getLogin() const;
    bool isMod() const;
private:
    Login* id;
    Profile* prf;
    bool isModerator;
};

class Subscriber : public User {
public:
    Subscriber(Login* =0, Profile* =0, bool = false);
};

class Moderator : public User {
public:
    Moderator(Login* =0, Profile* =0, bool = true);
};

class Profile {
public:
    Profile(const QString&);
private:
    QString bio;
    // avatar?
};

class Login {
public:
    Login(const QString&, const QString&, const QString&);
    QString getUsername() const;
    QString getEmail() const;
    QString getPassword() const;
    bool operator==(Login); // overloading operator == ... two Logins are equals if the username are equals
private:
    QString username;       // UNIQUE: can NOT be changed
    QString email;          // UNIQUE: can be changed
    QString password;       // can be changed
};

#endif // USER_H
