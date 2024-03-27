# Model-informed path planning and control for autonomous vessels

![GitHub_Action_Linux_CI](https://github.com/AtsushiSakai/PythonRobotics/workflows/Linux_CI/badge.svg)

## Project description

This respository is a part of diploma thesis at the Faculty of Electrical Engineering and Computing, University of Zagreb. The main goal of the thesis is to develop a model-informed path planning and control for autonomous vessels.  The project is based on the PythonRobotics repository and it is used for educational purposes only.
 Model-informed path planning consists of the following steps:
1. Data extraction and processing from OpenStreetMap
3. Testing of the path planning algorithms from the PythonRobotics repository on the extracted OpenStreetMap data 
4. Path interpolation
5. Cost map generation
6. Testing of the path planning algorithms on the generated cost map
7. Publishing data to the ROS2 environment and testing the path planning algorithms on the real vessel or in the simulation environment



## Table of Contents

   * [Installing](##installing)
   * [Requirements](##requirements)
   * [Executing program](##executing-program)
        * [Executing program](##executing-program)


## Installing
```terminal
git clone https://github.com/kr1zzo/Model-informed-path-planning.git
```

## Requirements

 ```terminal
  pip install -r requirements/requirements.txt
  ```

## Executing program

* How to run the program
* Step-by-step bullets

## Step 1 : Download data from OpenStreetMap (optional)

In the folder `input_data` are proveided default data for the following locations:
- Voz, island of Krk, Croatia
- Jadranovo, Croatia

Feel free to download your own data from OpenStreetMap and follow the instructions below.

1.1. Go to [OpenStreetMap](https://www.openstreetmap.org/#map=15/45.2359/14.5844) and select the area you want to download.

1.2. Make new folder `geolocation_name` (for example `Rijeka`) in the `input_data` folder and put `osm_data.txt` file inside

1.3. Click on the Download button and download the data in .png format

<img src="assets/osm_download.png" alt="drawing" width="200"/>



1.3. Copy the downloaded .png file to the `input_data/geolocation_name` folder

1.4. Copy  HTML string from the OpenStreetMap website and paste it into the `input_data/geolocation_name` folder in the `osm_data.txt` file for extrcation of the coordinates

<img src="assets/osm_geolocation.png" alt="drawing" width="200"/>

1.4. Update config.yaml file




## Credits

#### &copy; Faculty of Electrical Engineering and Computing, University of Zagreb, 2024

#### &copy; Laboratory for Underwater Systems and Technologies (LABUST)

<img src="assets/labust_logo.png" alt="drawing" width="50"/>
<img src="assets/FER_logo_3.png" alt="drawing" width="200"/>

&NewLine;

Contributors names and contact info

Author|GitHub | e-mail
| :--- | :---: | :---:
Enio Krizman  | [@kr1zzo](https://github.com/kr1zzo) | enio.krizman@fer.hr

Mentors | e-mail
| :--- | :---: 
Doc. Dr. Sc. Đula Nađ  | dula.nad@fer.hr
Dr. Sc. Nadir Kapetanović  | nadir.kapetanovi@fer.hr

## Acknowledgments

This repository is build using the following resources and it is used only for educational purposes:
* [PythonRobotics](https://github.com/AtsushiSakai/PythonRobotics)
