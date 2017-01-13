#!/usr/local/bin/python3
import models as dbH
 
def add_image() -> int:
    """Adds image id to database, and returns
    image id. 
    """    
    id = dbH.insert_image() 
    return str(id)

def delete_images(imageId, apiKey = None) -> str:
    return 'do some magic!'

def get_images_by_id(imageId) -> str:
    return 'do some magic!'
