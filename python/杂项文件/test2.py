
# coding=gbk

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import statsmodels.api as sm
import scipy.stats as stats
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
import csv
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import mean_squared_error
from sklearn.metrics import f1_score
from sklearn.metrics import classification_report
import math

def mutline():
    plt.style.use('ggplot')
    plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
    data = pd.read_csv("com_E_work_and_week_all.csv")
    print(data.iloc[:,0:3])
    num = []
    for i in range(0,11):
        X_train, X_test, Y_train, Y_test = train_test_split(data.iloc[:,i:i+12], data.iloc[:,i+12], train_size=0.8)
        print("原始数据集:", data.iloc[:,i:i+12].shape,
              ",训练数据集:", X_train.shape,
              ",测试数据集:", X_test.shape)

        print("原始数据标签:", data.iloc[:,i+12].shape,
              ",训练数据标签:", Y_train.shape,
              ",测试数据标签:", Y_test.shape)
        model = LinearRegression()
        model.fit(X_train,Y_train)
        a = model.intercept_
        b = model.coef_
        print("最佳拟合线:截距 ", a, ",回归系数：", b)
        score = model.score(X_test, Y_test)
        print("决定系数R^2:",score)
        Y_pred = model.predict(X_test)
        num.append(Y_pred)
        a2 = mean_squared_error(Y_test,Y_pred)
        a2 = math.sqrt(a2)
        print("均方根误差:", a2)

if __name__ == '__main__':
    mutline()
