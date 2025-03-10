"""
@file: curve_example.py
@breif: curve generation application examples
@author: Winter
@update: 2023.7.25
"""
import sys, os
import sys
import pickle
from pathlib import Path
import yaml
import math
import matplotlib.pyplot as plt
from curve_generation.curve_factory import CurveFactory
from matplotlib.lines import Line2D

root = Path(__file__).resolve().parents[2]


show_plot = True

def load_binary_data(file_name):
    binary_path = root / "binary_dump"
    with open(binary_path/file_name, "rb") as f:
        data = pickle.load(f)
    return data

def save_binary_data(data, file_name):
    binary_path = root / "binary_dump"
    with open(binary_path/file_name, "wb") as f:
        pickle.dump(data, f)



class PathOptimization:

	def __init__(self, points, method="dubins", show_results=False, sampling_rate=5.0):
		self.points = points
		self.points_new = []
		self.points_new1 = []
		self.method = method
		self.path_points = []
		self.show_results = show_results
		self.sampling_rate = sampling_rate
		self.plot_interpolation = []


	def get_path(self):
		return self.path_points	
	
	def get_interpolation(self):
		return self.plot_interpolation
	
	def get_angle(self,x1, y1, x2, y2):
		return math.degrees(math.atan2(y2-y1, x2-x1))

	def euclidean_distance(self,x1, y1, x2, y2):
		return math.sqrt((x1-x2)**2 + (y1-y2)**2)

	def triangle_angle(self,previous_point, next_point, point):
		a = self.euclidean_distance(previous_point[0], previous_point[1], point[0], point[1])
		b = self.euclidean_distance(point[0], point[1], next_point[0], next_point[1])
		c = self.euclidean_distance(previous_point[0], previous_point[1], next_point[0], next_point[1])

		try:
			angle = math.acos((a**2 + b**2 - c**2) / (2*a*b))
		except:
			angle = 180
		
		return math.degrees(angle)
	
	def optimize_path(self):

		for i, point in enumerate(self.points):
			if i == 0:
				self.points_new.append(point)
				continue
			if i == len(self.points)-self.sampling_rate:
				break
				
			angle = self.triangle_angle(self.points[i-1], self.points[i+1], point)
			if angle < 150 or i%self.sampling_rate == 0:
				self.points_new.append(point)
		
		self.points_new.append(self.points[-1])
	
		points_new_plot = self.points_new.copy()

		has_acute_angle = True
		j = 0
		while has_acute_angle:
			j += 1
			print("iteration: ", j)
			has_acute_angle = False
			removed_points = []
			new_points = []

			for i, point in enumerate(self.points_new):
				if i == 0:
					continue
				if i == len(self.points_new)-1:
					continue
				angle = self.triangle_angle(self.points_new[i-1], self.points_new[i+1], point)
				if angle ==180 or angle == 0:
					continue
				elif angle < 150:
					#removed_points.append(self.points_new[i])
					new_x = (self.points_new[i-1][0]+self.points_new[i+1][0])/2
					new_y = (self.points_new[i-1][1]+self.points_new[i+1][1])/2
					self.points_new[i] = (new_x, new_y)
					has_acute_angle = True
				elif angle > 150 and angle <180:
					new_x = (self.points_new[i-1][0]+self.points_new[i+1][0])/2
					new_y = (self.points_new[i-1][1]+self.points_new[i+1][1])/2
					self.points_new[i] = (new_x, new_y)
				elif angle > 180:
					print("angle 150 ", angle)
					try:
						y1 = self.points_new[i-1][1]
						y2 = self.points_new[i+1][1]
						x1 = self.points_new[i-1][0]
						x2 = self.points_new[i+1][0]
						#print(x1, y1, x2, y2)
						quadrant_angle = self.get_angle(x1, y1, x2, y2)
						print("quadrant_angle: ", quadrant_angle)
						c = self.euclidean_distance(x1, y1, x2, y2)
						a = math.sqrt(c**2/(2*(1-math.cos(math.radians(135)))))
						print("a: ", a)
						if quadrant_angle >= 0 and quadrant_angle < 90:
							delta_x = a*math.cos(math.radians(45))
							delta_y = a*math.sin(math.radians(45))
							new_point = (x1+delta_x, y1+delta_y)
						elif quadrant_angle >= 90 and quadrant_angle < 180:
							delta_x = a*math.cos(math.radians(45))
							delta_y = a*math.sin(math.radians(45))
							new_point = (x1-delta_x, y1+delta_y)
						elif quadrant_angle < 0 and quadrant_angle >= -90:
							delta_x = a*math.cos(math.radians(45))
							delta_y = a*math.sin(math.radians(45))
							new_point = (x1+delta_x, y1-delta_y)
						elif quadrant_angle < -90 and quadrant_angle >= -180:
							delta_x = a*math.cos(math.radians(45))
							delta_y = a*math.sin(math.radians(45))
							new_point = (x1-delta_x, y1-delta_y)
					except:
						pass
				for point in removed_points:
					try:
						self.points_new.remove(point)
					except:
						pass
				removed_points = []
	

				for element in new_points:
					i = element[1]
					new_point = element[0]
					self.points_new.insert(i, new_point)
				new_points = []
		
		for i, point in enumerate(self.points_new):
			if i == 0:
					continue
			if i == len(self.points_new)-1:
					continue
			angle = self.triangle_angle(self.points_new[i-1], self.points_new[i+1], point)
			if angle > 150 or angle <180:
				new_x = (self.points_new[i-1][0]+self.points_new[i+1][0])/2
				new_y = (self.points_new[i-1][1]+self.points_new[i+1][1])/2
				self.points_new[i] = (new_x, new_y)


		points_new_plot1 = self.points_new.copy()

		for i, point in enumerate(self.points_new):
			self.points_new[i] = (point[0], point[1], self.get_angle(self.points_new[i-1][0], self.points_new[i-1][1], point[0], point[1])) if i != 0 else (point[0], point[1], self.get_angle(point[0], point[1],self.points_new[i+1][0], self.points_new[i+1][1]))
		
		curve_factory = CurveFactory()
		# create generator
		if self.method == "dubins":
			generator = curve_factory("dubins", step= 0.1, max_curv=0.2)
		elif self.method == "bezier":
			generator = curve_factory("bezier", step=0.1, offset=3.0)
		elif self.method == "polynomial":
			generator = curve_factory("polynomial", step=2, max_acc=1.0, max_jerk=0.5)
		elif self.method == "reeds_shepp":
			generator = curve_factory("reeds_shepp", step=0.1, max_curv=0.25)
		elif self.method == "cubic_spline":
			generator = curve_factory("cubic_spline", step=0.1)
		elif self.method == "bspline":
			generator = curve_factory("bspline", step=0.01, k=3)
		elif self.method == "fem_pos_smoother":
			generator = curve_factory("fem_pos_smoother", w_smooth=10, w_ref=1, w_length=1, dx_l=0.2, dx_u=0.2, dy_l=0.2, dy_u=0.2)

		path_x,path_y,return_list = generator.run(self.points_new)

		path_points = [(path_x[i], path_y[i]) for i in range(len(path_x))]

		points = [(self.points[i][0], self.points[i][1]) for i in range(len(self.points))]

		self.path_points = path_points



		self.plot_interpolation = [points, points_new_plot, points_new_plot1, path_points]

		return
	
if __name__ == "__main__":
	points = load_binary_data("internal_data")
	path_optimization = PathOptimization(points, method="dubins")
	path_optimization.optimize_path()




	

