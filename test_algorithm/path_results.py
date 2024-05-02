
class PathResults():
    def __init__(self, algorithm_name, start,goal, path : list, distance=0.0, predicted_travel_time=0.0):
        self.algorithm_name = algorithm_name
        self.start = start
        self.goal = goal    
        self.path = path
        self.distance = distance
        self.predicted_travel_time = predicted_travel_time
    
    def set_algorithm_name(self, algorithm_name):
        self.algorithm_name = algorithm_name
    
    def set_start(self, start):
        self.start = start
    
    def set_goal(self, goal):
        self.goal = goal

    def set_path(self, path):
        self.path = path
    
    def set_distance(self, distance):
        self.distance = distance
    
    def set_predicted_travel_time(self, predicted_travel_time):
        self.predicted_travel_time = predicted_travel_time
    
    def get_algorithm_name(self):
        return self.algorithm_name
    
    def get_start(self):
        return self.start
    
    def get_goal(self):
        return self.goal

    def get_path(self):
        return self.path

    def get_distance(self):
        return self.distance
    
    def get_predicted_travel_time(self):
        return self.predicted_travel_time

class PathResultsInternal(PathResults):
    def __init__(self, algorithm_name, start,goal, path : list, distance=0.0, predicted_travel_time=0.0, runtime=0.0):
        super().__init__(algorithm_name, start,goal, path, distance, predicted_travel_time)
        self.runtime = runtime
    
    def set_runtime(self, runtime):
        self.runtime = runtime
    
    def get_runtime(self):
        return self.runtime
    