DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id integer primary key autoincrement,
    username text not null,
    password text not null
);

DROP TABLE IF EXISTS images;
CREATE TABLE images (
    id integer primary key autoincrement
);




