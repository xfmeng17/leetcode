# -*- coding:utf-8 -*-

import os

for file in os.listdir("../cpp"):
    idx1 = file.find('_')
    idx2 = file.find('.')
    if idx1 == -1 or idx2 == -1 :
        continue
    os.rename(file, file[0:idx1] + file[idx2:])