
import imageio.v3 as iio
import ipympl
import matplotlib.pyplot as plt
import numpy as np
import skimage as ski
import cv2
import numpy as np
from skimage import io, measure
from scipy import ndimage as nd
from skimage.color import label2rgb
import imghdr

def get_edges(image):
    edges = cv2.Canny(image,100,200)
    indices = np.where(edges != [0])
    return indices

if __name__ == '__main__':

    image_1 = io.imread('kvarner.png')
    #plt.imshow(image)
    #plt.show()
    
    hsv = cv2.cvtColor(image_1, cv2.COLOR_RGB2HSV)
    #plt.imshow(hsv)
    #plt.show()
    lower_blue = np.array([80, 60,60])
    upper_blue = np.array([120, 255, 255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)


    #plt.imshow(mask)
    #plt.show()

    closed = nd.binary_closing(mask, structure=np.ones((7,7)))
    #plt.imshow(closed)
    #plt.show()

    label_image = measure.label(closed)
    plt.imshow(label_image)
    plt.show()
    #print(label_image)

    picture_values = []

    rows, cols = label_image.shape
    for i in range(rows):
        for j in range(cols):
            k = label_image[i][j]
            if k not in picture_values:
                picture_values.append(k)
            #print(k)
            if k == 28:
                label_image[i][j] = 255
            else:
                label_image[i][j] = 0
    #elements_count = {i:picture_values.count(i) for i in picture_values}

    #print(elements_count)

    #print(max(elements_count, key = elements_count.get))
    #plt.imshow(label_image, cmap='gray')
    #plt.show()
    #for element in picture_values:
    #    print(element)

    plt.imsave('kvarner_bw.png', label_image,cmap='gray')

    image_uint8 = image_1.astype(np.uint8)
    img_blur = cv2.GaussianBlur(image_uint8,(5,5),0)
    sobelx = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=0, ksize=5) # Sobel Edge Detection on the X axis
    sobely = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=0, dy=1, ksize=5) # Sobel Edge Detection on the Y axis
    sobelxy = cv2.Sobel(src=img_blur, ddepth=cv2.CV_64F, dx=1, dy=1, ksize=5) # Combined X and Y Sobel Edge Detection
    #Display Sobel Edge Detection Images
    cv2.imshow('Sobel X Y using Sobel() function', sobelxy)

    # Canny Edge Detection
    edges = cv2.Canny(image=img_blur, threshold1=100, threshold2=200) # Canny Edge Detection
    # Display Canny Edge Detection Image
    #cv2.imshow('Canny Edge Detection', edges)
    #cv2.waitKey(0)

    
