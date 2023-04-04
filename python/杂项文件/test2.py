
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
        print("ԭʼ���ݼ�:", data.iloc[:,i:i+12].shape,
              ",ѵ�����ݼ�:", X_train.shape,
              ",�������ݼ�:", X_test.shape)

        print("ԭʼ���ݱ�ǩ:", data.iloc[:,i+12].shape,
              ",ѵ�����ݱ�ǩ:", Y_train.shape,
              ",�������ݱ�ǩ:", Y_test.shape)
        model = LinearRegression()
        model.fit(X_train,Y_train)
        a = model.intercept_
        b = model.coef_
        print("��������:�ؾ� ", a, ",�ع�ϵ����", b)
        score = model.score(X_test, Y_test)
        print("����ϵ��R^2:",score)
        Y_pred = model.predict(X_test)
        num.append(Y_pred)
        a2 = mean_squared_error(Y_test,Y_pred)
        a2 = math.sqrt(a2)
        print("���������:", a2)

if __name__ == '__main__':
    mutline()
