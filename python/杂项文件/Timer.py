# -*- coding:GBK -*-

import time as tm

class MyTimer():
    def __init__(self):
        self.unit = ['��', '��', '��', 'ʱ', '��', '��']
        self.begin = 0
        self.end = 0
        self.prompt = "δ��ʼ��ʱ������"
        self.sumTime = []

    def __str__(self):
        return self.prompt

    #��ʼ��ʱ
    def start(self):
        self.begin = tm.localtime()
        self.prompt = '��ʾ������ֹͣ��ʱ������'
        print("��ʼ��ʱ......")
    
    #ֹͣ��ʱ
    def stop(self):
        if not self.begin:
            print('�㻹û��ʼ��ʱ��ɵ��������')
        else:
            self.end = tm.localtime()
            self._calc()
            print("��ʱ����������")
    
    def _calc(self):
        self.prompt = '�ܹ�������'
        for i in range(6):
            self.sumTime.append(self.end[i] - self.begin[i])
            if self.sumTime[i]:
                self.prompt += str(self.sumTime[i]) + self.unit[i]

t1 = MyTimer()

tm.sleep(3)
t1.stop()
t1.start()
print(t1)