# -*- coding: utf-8 -*-
"""
Created on Thu Oct  4 19:17:31 2018

@author: hp
"""

import pandas as pd
diabetes_dataset=pd.read_csv("02_PimaIndiansDiabetes.csv",delimiter=',')

X=diabetes_dataset.iloc[:,:-1].values
y=diabetes_dataset.iloc[:,-1].values



from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X=sc.fit_transform(X)

from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.20,random_state=0)

from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X_train,y_train)

y_pred=classifier.predict(X_test)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test , y_pred)

def accuracy(cm):
    diagonal_sum = cm.trace()
    total_sum = cm.sum()
    return diagonal_sum/total_sum
	
accuracy(cm)