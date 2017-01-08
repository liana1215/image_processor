#!/usr/bin/env python3

from flask import Flask, g, render_template, request
import connexion

def create_app(debug=False):
    app = Flask(__name__)
    app.debug = debug

    #configure app
    app.config.update(dict(
        USERNAME='admin',
        PASSWORD='default'
    ))
    
    return app




if __name__ == '__main__':
    app = connexion.App(__name__, specification_dir='./swagger/')
    app.add_api('swagger.yaml', arguments={'title': 'This is a server that stores images, and returns processed images on demand.'})
    app.run(port=8080)
