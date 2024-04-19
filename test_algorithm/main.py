"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""

import threading
import sys
from test import test
from plot import plot

def main():
    test()
    plot()
    
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
