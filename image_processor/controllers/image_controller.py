#!/usr/local/bin/python3
from werkzeug.utils import secure_filename 
import models as dbH

IMG_BANK_PATH = '/workspace/project/image-processor/image-processor/image_bank/'

def add_image(f=None) -> int:
    """Adds image id to database, stores image to path
    and returns image id. 
    """    
    id = dbH.insert_image() 
    if f:
        f_name = secure_filename(f.filename)
        f.save(os.path.join(IMG_BANK_PATH, f_name))

    return str(id)

def delete_images(imageId, apiKey = None) -> str:
    return 'do some magic!'

def get_images_by_id(imageId) -> str:
    return 'do some magic!'
