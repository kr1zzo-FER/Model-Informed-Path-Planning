

from skimage import io, measure
from PIL import Image
import pickle


def main():
    
    # set obstacle positions
    image_pixel = Image.open('jadranovo_bw.png')
    image_pixel_rgb = Image.open('jadranovo.png')

    resize_factor = 8

    image_pixel = image_pixel.resize((image_pixel.size[0]//resize_factor, image_pixel.size[1]//resize_factor))
    image_pixel_rgb = image_pixel_rgb.resize((image_pixel_rgb.size[0]//resize_factor, image_pixel_rgb.size[1]//resize_factor))

    print(image_pixel.size)
    ox, oy = [], []
    for i in range(0, image_pixel.size[0]):
        ox.append(i)
        oy.append(0)
    for i in range(0, image_pixel.size[1]):
        ox.append(0)
        oy.append(i)
    for i in range(0, image_pixel.size[1]):
        ox.append(image_pixel.size[0])
        oy.append(i)
    for i in range(0, image_pixel.size[0]):
        ox.append(i)
        oy.append(image_pixel.size[1])
    
    px = image_pixel.load()
    for i in range(0, image_pixel.size[0]):
        for j in range(0, image_pixel.size[1]):
            #print(image_pixel.size[0])
            #print(i+1)
            if (i+1) >= image_pixel.size[0] or (j+1) >= image_pixel.size[1]:
                #print("break")
                break
            if px[i,j] != px[i+1,j+1]: #or px[i,j] != px[i+1,j] or px[i,j] != px[i,j+1] or px[i,j] != px[i-1,j] or px[i,j] != px[i,j-1] or px[i,j] != px[i-1,j-1] or px[i,j] != px[i-1,j+1] or px[i,j] != px[i+1,j-1]:
                ox.append(i)
                oy.append(image_pixel.size[1]-j)
    
    with open("ox", "wb") as f:
        pickle.dump(ox, f)
    with open("oy", "wb") as f:
        pickle.dump(oy, f)
    with open("dim_x", "wb") as f:
        pickle.dump(image_pixel.size[0], f)
    with open("dim_y", "wb") as f:
        pickle.dump(image_pixel.size[1], f)
    
    image_pixel.show()

    image_pixel.save("jadranovo_bw_resized.png")
    image_pixel_rgb.save("jadranovo_resized.png")
    
    

    
if __name__ == '__main__':
    main()
