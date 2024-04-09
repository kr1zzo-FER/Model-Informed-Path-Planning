"""

Thread module for running the main functions of the project in parallel.

author: Enio Krizman (@kr1zzo)

"""

import threading
import sys
from test import test
from plot import plot

def main():
    thread2 = threading.Thread(target=test)
    thread2.start()
    thread2.join()
    thread3 = threading.Thread(target=plot)
    thread3.start()
    thread3.join()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
