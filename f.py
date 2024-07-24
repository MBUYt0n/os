# import matplotlib.pyplot as plt
# import random
# import numpy as np


# def x():
#     b = np.zeros((100, 100, 3))
#     for i in range(100):
#         a = np.array(
#             [
#                 [
#                     (
#                         random.randint(0, 255) / 255.0,
#                         random.randint(0, 255) / 255.0,
#                         random.randint(0, 255) / 255.0,
#                     )
#                     for i in range(100)
#                 ]
#                 for j in range(100)
#             ]
#         )
#         b = (b + a) / 2.0
#     return b


# plt.imshow(x())
# plt.show()


import pyperclip
import sys

x = sys.argv[1] 
x = "".join([j.upper() if i % 2 == 0 else j for i, j in enumerate(x)])
pyperclip.copy(x)
