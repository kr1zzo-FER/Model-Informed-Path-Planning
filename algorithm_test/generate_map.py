
"""

Map generation script

author: Enio Krizman (@kr1zzo)

"""


from skimage import io, measure
from PIL import Image
import pickle
from pathlib import Path
from pathlib import Path
import yaml
import matplotlib.pyplot as plt
from matplotlib.backend_bases import MouseButton
counter = 0

def onclick(event):
    root = Path(".")

    my_path = root / "binary_dump"
    images = root / "images"
    global counter
    if event.button == MouseButton.LEFT:
        if counter == 0:
            print("Start position set")
            with open(my_path/"sx", "wb") as f:
                pickle.dump(event.xdata, f)
            with open(my_path/"sy", "wb") as f:
                pickle.dump(event.ydata, f)
            counter += 1
        elif counter == 1:
            print("Goal position set")
            with open(my_path/"gx", "wb") as f:
                pickle.dump(event.xdata, f)
            with open(my_path/"gy", "wb") as f:
                pickle.dump(event.ydata, f)
            exit(0)


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

    fig, ax = plt.subplots()
    im = ax.imshow(image_pixel_rgb, extent=[0, image_pixel.size[0], 0, image_pixel.size[1]])
    
    ax.set_title("Left mouse click - set start and goal positions")

    fig.canvas.mpl_connect('button_press_event', onclick)

    plt.show()
    

    
if __name__ == '__main__':
    main()
