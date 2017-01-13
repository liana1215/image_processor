#!/usr/local/bin/python3

import os

from flask import Flask, Blueprint, g, request
from werkzeug.utils import secure_filename
import controllers.image_controller as imgc

view = Blueprint('view', __name__)
IMG_BANK_PATH = '/workspace/project/image-processor/image-processor/image_bank/'
#http://flask.pocoo.org/docs/0.12/patterns/fileuploads/
@view.route('/images', methods=['POST','GET'])
def images():
    if request.method == 'POST':
        ret_id = imgc.add_image()
        #f = request.files["file"]
        #if f:
        #    f_name = secure_filename(f.filename)
        #    f.save(os.path.join(IMG_BANK_PATH, f_name))
            
        #add image to dir with id
        return ret_id
       
