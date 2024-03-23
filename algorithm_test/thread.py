import threading

from generate_map import main as map_main
from plot_algorithms import main as plot_main
from test_algorithms import main as test_main


def main():
    thread1 = threading.Thread(target=map_main)
    thread1.start()
    thread1.join()
    thread2 = threading.Thread(target=test_main)
    thread2.start()
    thread2.join()
    thread3 = threading.Thread(target=plot_main)
    thread3.start()
    thread3.join()

if __name__ == '__main__':
    main()