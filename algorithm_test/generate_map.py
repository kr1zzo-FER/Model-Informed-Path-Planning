

from skimage import io, measure
from PIL import Image
import pickle
from pathlib import Path
from pathlib import Path
import yaml
def main():
    
    # set obstacle positions
    root = Path(".")

    binary_path = root / "binary_dump"
    images = root / "images"

    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        image_pixel = config["start_image_name_bw"]
        image_pixel_rgb = config["start_image_name"]

    image_pixel = Image.open(images/'jadranovo_bw.png')
    image_pixel_rgb = Image.open(images/'jadranovo.png')

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
    
    root = Path(".")

    my_path = root / "binary_dump"
    images = root / "images"


    with open(my_path/"ox", "wb") as f:
        pickle.dump(ox, f)
    with open(my_path/"oy", "wb") as f:
        pickle.dump(oy, f)
    with open(my_path/"dim_x", "wb") as f:
        pickle.dump(image_pixel.size[0], f)
    with open(my_path/"dim_y", "wb") as f:
        pickle.dump(image_pixel.size[1], f)
    
    #image_pixel.show()

    image_pixel.save(images/"jadranovo_bw_resized.png")
    image_pixel_rgb.save(images/"jadranovo_resized.png")
    
    

    
if __name__ == '__main__':
    main()
