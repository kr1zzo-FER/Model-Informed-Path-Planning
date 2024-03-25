
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
x_width = 0
y_width = 0
grid_size = 0
start = []
def onclick(event):
    root = Path(".")

    my_path = root / "binary_dump"
    images = root / "images"
    global counter
    global grid_size
    global start
    global x_width
    global y_width
    if event.button == MouseButton.LEFT:
        if counter == 0:
            print(f"Start position set: {event.xdata}, {event.ydata}")
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            with open(my_path/"sx", "wb") as f:
                pickle.dump(x_data, f)
            with open(my_path/"sy", "wb") as f:
                pickle.dump(y_data, f)
            print(f"Start position for calculation: {x_data}, y: {y_data}")
            counter += 1
        elif counter == 1:
            print(f"Goal position set: {event.xdata}, {event.ydata}")
            x_data = int(round(event.xdata/grid_size)*grid_size)
            y_data = int(round(event.ydata/grid_size)*grid_size)
            with open(my_path/"gx", "wb") as f:
                pickle.dump(x_data, f)
            with open(my_path/"gy", "wb") as f:
                pickle.dump(y_data, f)
            print(f"Goal position for calculation: {x_data}, y: {y_data}")
    elif event.button == MouseButton.RIGHT:
        print("End of setting start and goal positions")
        plt.close()
        exit(0)



def pixel_to_meters(size_x, size_y):
        image_width_height_m = []
        with open("binary_dump/image_width_height_m", "rb") as f:
            image_width_height_m = pickle.load(f)
        
        #print(image_width_height_m)
        factorx = image_width_height_m[0] / size_x
        factory = image_width_height_m[1] / size_y

        #print(size_x, size_y)
        #print(factorx, factory)
        #print(size_x*factorx)

        return factorx, factory

def main():
    print(__file__ + " start!!")
    # set obstacle positions
    root = Path(".")

    binary_path = root / "binary_dump"
    images = root / "images"

    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        image_pixel = config["start_image_name_bw"]
        image_pixel_rgb = config["start_image_name"]
        image_save = config["image_save"]
        image_save_bw = config["image_save_bw"]

    image_pixel = Image.open(images/image_pixel)
    image_pixel_rgb = Image.open(images/image_pixel_rgb)

    resize_factor = 4

    #print(image_pixel.size[0])

    factorx, factory = pixel_to_meters(image_pixel.size[0], image_pixel.size[1])

    factorx = int(round(image_pixel.size[0]*factorx))
    factory = int(round(image_pixel.size[1]*factory))
    #print(factorx)
    #print(factory)


    image_pixel = image_pixel.resize((factorx, factory))

    image_pixel_rgb = image_pixel_rgb.resize((factorx, factory))

    #print(image_pixel.size)
    ox, oy = [], []
    
    global grid_size
    with open("config.yaml", "r") as f:
        config = yaml.safe_load(f)
        grid_size = int(config["grid_size"])
    
    #print(image_pixel.size[0], image_pixel.size[1])
    global x_width
    
    x_width = round(image_pixel.size[0]/ grid_size)
    y_width = round(image_pixel.size[1]/ grid_size)
    #print(x_width*y_width)

    #print(x_width, y_width)
    px = image_pixel.load()

    for i in range(0, x_width-1):
        for j in range(0, y_width-1):

            
            pixel_i = i*grid_size
            pixel_j = j*grid_size


            try:
                if px[pixel_i, pixel_j] != px[(i+1)*grid_size, (j+1)*grid_size] or px[pixel_i, pixel_j] != px[(i+1)*grid_size, j*grid_size] or px[pixel_i, pixel_j] != px[i*grid_size, (j+1)*grid_size]:
                        ox.append(pixel_i)
                        #print(image_pixel.size[1] - pixel_j)
                        oy.append(image_pixel.size[1] - pixel_j)
            except:
                pass

    root = Path(".")

    my_path = root / "binary_dump"
    images = root / "images"


    with open(my_path/"ox", "wb") as f:
        pickle.dump(ox, f)
    with open(my_path/"oy", "wb") as f:
        pickle.dump(oy, f)
    with open(my_path/"dim_x", "wb") as f:
        print(image_pixel.size[0])
        pickle.dump(image_pixel.size[0], f)
    with open(my_path/"dim_y", "wb") as f:
        pickle.dump(image_pixel.size[1], f)
    
    #image_pixel.show()
        
    max_x = round(max(ox))
    max_y = round(max(oy))
    #print(max_x, max_y)

    image_pixel.save(images/image_save_bw)
    image_pixel_rgb.save(images/image_save)

    fig, ax = plt.subplots()

    im = ax.imshow(image_pixel_rgb, extent=[0, image_pixel_rgb.size[0], 0, image_pixel_rgb.size[1]])
    
     
    ax.set_title("Left mouse click - set start and goal positions, end with right mouse click")
    for ox, oy in zip(ox, oy):
        ax.plot(ox, oy, 'ro')

    fig.canvas.mpl_connect('button_press_event', onclick)


    plt.show()

    
if __name__ == '__main__':
    main()
