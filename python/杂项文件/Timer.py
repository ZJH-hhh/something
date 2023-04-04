# -*- coding:GBK -*-

import time as tm

class MyTimer():
    def __init__(self):
        self.unit = ['年', '月', '日', '时', '分', '秒']
        self.begin = 0
        self.end = 0
        self.prompt = "未开始计时！！！"
        self.sumTime = []

    def __str__(self):
        return self.prompt

    #开始计时
    def start(self):
        self.begin = tm.localtime()
        self.prompt = '提示：请先停止计时！！！'
        print("开始计时......")
    
    #停止计时
    def stop(self):
        if not self.begin:
            print('你还没开始计时，傻杯！！！')
        else:
            self.end = tm.localtime()
            self._calc()
            print("计时结束！！！")
    
    def _calc(self):
        self.prompt = '总共运行了'
        for i in range(6):
            self.sumTime.append(self.end[i] - self.begin[i])
            if self.sumTime[i]:
                self.prompt += str(self.sumTime[i]) + self.unit[i]

t1 = MyTimer()

tm.sleep(3)
t1.stop()
t1.start()
print(t1)