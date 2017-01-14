#!/usr/local/bin/python3

import os

from flask import Flask, Blueprint, g, request, flash
import controllers.image_controller as imgc

view = Blueprint('view', __name__)

#http://flask.pocoo.org/docs/0.12/patterns/fileuploads/
@view.route('/images', methods=['POST','GET'])
def images():
    if request.method == 'POST':
        
        if 'file' not in request.files:
            print('No file')
        else:
            ret_id = imgc.add_image(request.files['file'])
                

        ret_id = imgc.add_image() # this will be removed, just for prototyping
        return ret_id

        
