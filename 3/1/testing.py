import random
import os
import time
import matplotlib.pyplot as plt
import numpy

for i in range(2, 7):
    f = open(f"numbers-10^{i}.txt", "w")
    for j in range(pow(10, i)):
        x = random.randint(-10000, 10000)
        y = random.randint(-10000, 10000)
        f.write(f"{x} {y}\n")
    f.close()

for i in range(2,7):
    filename = f"numbers-10^{i}.txt"

    start = time.time()
    os.system(f"./1.o {filename}")
    end = time.time()
    el1 = end - start

    start = time.time()
    os.system(f"./1if.o {filename}")
    end = time.time()
    el2 = end - start

    print(f"10^{i} skaiciu poru:")
    print(f"Be ifu : {el1}")
    print(f"Su ifais : {el2}")