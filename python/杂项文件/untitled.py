# -*- coding:GBK -*-

class Cat:
    """����һ��è��"""
 
    def __init__(self, new_name, new_age):
        """�ڴ��������֮�� ���Զ�����, ����ɶ���ĳ�ʼ���Ĺ���"""
        # self.name = "��ķ"
        # self.age = 20
        self.name = new_name
        self.age = new_age  # ����һ�������е�����,�ڶ����д洢,��ֻҪ������󻹴���,��ô��������Ϳ���ʹ��
        # num = 100  # ����һ���ֲ�����,���������ִ����֮��,��������Ŀռ��û����,���������������ʹ���������
 
    def __str__(self):
        """����һ�������������Ϣ"""
        # print(num)
        return "������:%s , ������:%d" % (self.name, self.age)
 
    def eat(self):
        print("%s�ڳ���...." % self.name)
 
    def drink(self):
        print("%s�ںȿ���..." % self.name)
 
    def introduce(self):
        # print("������:%s, ������:%d" % (��ķ������, ��ķ������))
        # print("������:%s, ������:%d" % (tom.name, tom.age))
        print("������:%s, ������:%d" % (self.name, self.age))
 
# ������һ������
tom = Cat("��ķ", 30)
tom.drink()
tom.eat()
print(tom)