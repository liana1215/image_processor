import glob
import os
from subprocess import call

configpath = os.path.expanduser('~')
file_dir = "workspace/project/image-processor/workspace/images"

if __name__=="__main__":
    imgs = glob.glob("{}/*.png".format(os.path.join(configpath,file_dir)))
    for i,img in enumerate(imgs):
        try:
            call(["./ImageProcess", img, "{}.png".format(i)])
        except IOError:
            print("Call process failed.")

            


