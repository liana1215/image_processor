#!/usr/bin/env python3
import os
from sqlite3 import dbapi2 as sqlite3
from flask import Flask, g, request
from views import view
import models as dbH

#import connexion

configdb = "imagebank.db"
configschema = "schema.sql"
IMG_BANK_PATH = '/workspace/project/image-processor/image-processor/image_bank/'

def create_app(schema_uri, database_uri, debug=False):
    app = Flask(__name__)
    
    #configure app
    app.config.update(dict(
        DEBUG=debug,
        IMAGEFOLDER=IMG_BANK_PATH,
        SCHEMA=os.path.join(app.root_path, schema_uri),
        DATABASE=os.path.join(app.root_path, database_uri)
    ))
        
    app.register_blueprint(view)

    return app
    



if __name__ == '__main__':
    #app = connexion.App(__name__, specification_dir='./swagger/')
    #app.add_api('swagger.yaml', arguments={'title': 'This is a server that stores images, and returns processed images on demand.'})
    
    app = create_app(configschema, configdb, True)
    with app.app_context(): 
        dbH.initdb_command(app)

    app.run(port=8080)
