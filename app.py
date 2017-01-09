#!/usr/bin/env python3

from flask import Flask, g, render_template, request
import connexion





if __name__ == '__main__':
    app = connexion.App(__name__, specification_dir='./swagger/')
    app.add_api('swagger.yaml', arguments={'title': 'This is a server that stores images, and returns processed images on demand.'})
    app.run(port=8080)
