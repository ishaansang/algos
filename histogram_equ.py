import cv2
import numpy as np
from matplotlib import pyplot as plt
import cv2
import os

if not os.path.exists("./images_new"):
    os.makedirs("images_new")

folder = "../workspace/BTP/X-ray-classification/data/images"
# new_folder = './images_new'


def load_images_from_folder_and_process(folder):
    images = []
    image_name = []
    for filename in os.listdir(folder):
        img = cv2.imread(os.path.join(folder, filename), 0)
        equ = cv2.equalizeHist(img)
        # cv2.imwrite(os.path.join(new_folder , filename), equ)
        cv2.imwrite(filename, equ)


load_images_from_folder_and_process(folder)
