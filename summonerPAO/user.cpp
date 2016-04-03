#include "user.h"

/* IMPLEMENTATION OF USER */

User::User(Login* i, Profile* p, bool iM) : id(i), prf(p), isModerator(iM) {}

Login* User::getLogin() const { return id; }

bool User::isMod() const { return isModerator; }

/* IMPLEMENTATION OF SUBSCRIBER */

Subscriber::Subscriber(Login* i, Profile* p, bool iM) : User(i, p, iM) {}

/* IMPLEMENTATION OF MODERATOR */

Moderator::Moderator(Login* i, Profile* p, bool iM) : User(i, p, iM) {}

/* IMPLEMENTATION OF PROFILE */

Profile::Profile(const QString &b): bio(b) {}

/* IMPLEMENTATION OF LOGIN */

Login::Login(const QString& usr, const QString& em, const QString& pw) : username(usr), email(em), password(pw) {}

QString Login::getUsername() const { return username; }

QString Login::getEmail() const { return email; }

QString Login::getPassword() const { return password; }

bool Login::operator ==(Login log) { return log.getUsername() == username; }
