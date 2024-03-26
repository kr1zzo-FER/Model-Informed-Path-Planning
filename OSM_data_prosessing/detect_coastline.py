
"""

Map generation script

author: Enio Krizman (GitHub: @kr1zzo)

Copyright: © Faculty of Electrical Engineering and Computing, University of Zagreb

"""

import matplotlib.pyplot as plt
import numpy as np
import cv2
from pathlib import Path
from PIL import Image
from skimage import io, measure
from scipy import ndimage as nd
import pickle

def detect_edges(image_path, binary_path, grid_size, canny_detection = False):

    image = io.imread(image_path)

    image1 = Image.open(image_path)
    
    hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)

    lower_blue = np.array([80, 60,60])
    upper_blue = np.array([120, 255, 255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    ox, oy = [], []

    if canny_detection:
        kernel = np.ones((7,7),np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        #plt.imshow(mask)
        #plt.show()
        kern_size = 11
        gray_blurred = cv2.medianBlur(mask, kern_size)
        threshold_lower = 30
        threshold_upper = 220
        edged = cv2.Canny(gray_blurred, threshold_lower, threshold_upper)

        #print(edged.shape)
        
        print("\nFinding obstacles : Canny edge detection...\n")
        
        
        h,w = edged.shape
        x_width = round(w/ grid_size)
        y_width = round(h/ grid_size)

        px = edged

        for i in range(0, w):
            for j in range(0, h):

                try:
                    if edged[j,i]==255:
                        ox.append(round(i/grid_size)*grid_size)
                        oy.append(h-round(j/grid_size)*grid_size)

                except:
                    pass
        
    else:
        print("\nFinding obstacles : HSV mask...\n")

        mask = nd.binary_closing(mask, structure=np.ones((7,7)))
        h,w = mask.shape
        for i in range(0, w):
            for j in range(0, h):
                
                try:
                    if mask[j,i] != mask[j+1,i] or mask[j,i] != mask[j,i+1] or mask[j,i] != mask[j+1,i+1]:
                        ox.append(round(i/grid_size)*grid_size)
                        oy.append(h-round(j/grid_size)*grid_size)

                except:
                    pass
    
    # save obstacles to binary files
    with open(binary_path/"ox", "wb") as f:
        pickle.dump(ox, f)
    with open(binary_path/"oy", "wb") as f:
        pickle.dump(oy, f)
    with open(binary_path/"dim_x", "wb") as f:
        pickle.dump(image1.size[0], f)
    with open(binary_path/"dim_y", "wb") as f:
        pickle.dump(image1.size[1], f)
    
    print(f"Obstacles found!")

    return ox, oy

