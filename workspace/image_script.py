import glob
import os
from subprocess import call

configpath = os.path.expanduser('~')
file_dir = '/workspace/project/image-processor/workspace/images'

if __name__=="__main__":
    imgs = glob.glob('{}/*.png'.format(configpath+file_dir))
  
    for i,img in enumerate(imgs):
        call(["./BlurImage", img, "{}.png".format(i)])


