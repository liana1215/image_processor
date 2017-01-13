from flask import g
import sqlite3 as sql
from sqlite3 import dbapi2 as sqlite3

app = None

def initdb_command(wapp):
    global app
    app = wapp
    init_db()
    
def init_db():
    db = get_db()
    with app.open_resource(app.config['SCHEMA'], 'r') as f:
        db.cursor().executescript(f.read())
    db.commit()
    
def connect_db():
    rv = sqlite3.connect(app.config['DATABASE'])
    rv.row_factory = sqlite3.Row
    return rv

def get_db():
    if not hasattr(g, 'sqlite_db'):
        g.sqlite_db = connect_db()
    return g.sqlite_db

def close_db(error):
    if hasattr(g, 'sqlite_db'):
        g.sqlite_db.close()

def insert_image():
    db = get_db()
    cur = db.cursor()
    cur.execute(""" 
        INSERT INTO images 
        DEFAULT VALUES
    """)
    db.commit()
    id = cur.lastrowid
    return id

def delete_image(img_id):
    db = get_db()
    cur = db.cursor()
    cur.execute("""
        DELETE FROM images  
        WHERE ID=?
    """,(img_id))

    db.commit()

