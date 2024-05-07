
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]

sys.path.insert(0, str(root)+"/osm_data_processing")
from osm_data_processing import main as osm_main
from test_algorithms import main 
from osm_data_processing import test_results_visualization as test_results_visualization
from osm_data_processing import detect_coast 

def test_main():
    
    osm_main.main()
    main.main()
    test_results_visualization.main()

if __name__ == '__main__':
    test_main()