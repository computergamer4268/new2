# -*- coding: utf-8 -*-
"""
Created on Mon Oct  1 19:38:37 2018

@author: hp
"""

import pandas as pd
iris_dataset = pd.read_csv("iris.csv")

print("Number of features : ")
print(len(iris_dataset.columns))

iris_dataset.max(axis=0,numeric_only=True)

iris_dataset['Sepal Length'].min()

iris_dataset.mean(axis=0,numeric_only=True)

iris_dataset.describe()

iris_dataset.sum(axis=0,numeric_only=True)

iris_dataset['Sepal Length'].hist()

iris_dataset.boxplot()
