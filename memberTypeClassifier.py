# -*- coding: utf-8 -*-
"""
Created on Fri Oct  5 01:16:46 2018

@author: hp
"""

import pandas as pd
bike_dataset=pd.read_csv("bikesharedata.csv",delimiter=',')

bike_dataset.info()


X=bike_dataset.iloc[:,[0,3,5]].values
y=bike_dataset.iloc[:,8].values


from sklearn.preprocessing import LabelEncoder
labelencoder_y =LabelEncoder()
y = labelencoder_y.fit_transform(y)


from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.20,random_state=0)


from sklearn.tree import DecisionTreeClassifier
classifier = DecisionTreeClassifier()
classifier.fit(X_train,y_train)


y_pred = classifier.predict(X_test)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test,y_pred)
