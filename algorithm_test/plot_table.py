
import matplotlib.pyplot as plt
import pickle
import os 
from pathlib import Path
import yaml
root = Path(__file__).resolve().parents[1]

def main():

    global root
    binary_path = root / "binary_dump"
    results = root / "results"

    with open(root/"config.yaml", "r") as f:
        config = yaml.safe_load(f)
        table_name = config["table_name"]
        
    fig, ax = plt.subplots()

    rows = []
    columns = ['Time [s]', 'Distance [m]']
    values = []

    # hide axes
    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')
    ax.table(cellText=algorithm.values, colLabels=algorithm.columns, rowLabels=algorithm.rows, loc='center', cellLoc='center', colLoc='center')
    fig.tight_layout()
    plt.savefig(results/table_name)
    plt.show()
    
    

if __name__ == '__main__':
    main()
