#include "comment.h"

/* IMPLEMENTATION OF COMMENT */

Comment::Comment(const QString& usr, const QString& dt, const QString& txt) : user(usr), date(dt), text(txt) {}

QString Comment::getUser() const { return user; }

QString Comment::getDate() const { return date; }

QString Comment::getText() const { return text; }
