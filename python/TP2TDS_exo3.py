# -*- coding: utf-8 -*-
"""
Created on Fri Mar 14 08:53:00 2025

@author: arthu
"""

import numpy as np

def approximation(x,minV,maxV,c):
    step = (maxV-minV)/2**c
    x = np.array(x)
    x = np.floor((x-minV)/step)*step + minV
    print(x)


def main():
    
    x = [0.2, 0.7, 0.9, 1.2, 1.4, 1.8, 2.3]
    approximation(x, 1, 5, 3)

if __name__ == "__main__":
    main()      