
# coding=gbk

from urllib import response
import requests
import time
import pprint
import json
import demjson


def save(data):
    with open('data.json', 'a', encoding = 'utf-8') as file:
        file.write(json.dump(data, indent = 2, ensure_ascii = False))


def get_child_comment(mid):
    url = 'https://m.weibo.cn/comments/hotFlowChild?cid=' + mid + '&max_id=0&max_id_type=0'
    response = requests.get(url)
    data = response.json()
    print(data)


# 获取一条微博的热评
def get_hot_comments(mid):
    time.sleep(1)
    comment_url = 'https://m.weibo.cn/comments/hotflow?id=' + mid + '&mid=' + mid + '&max_id_type=0'
    response = requests.get(comment_url)
    data = response.json()
    data_list = data['data']['data']
    for data in data_list:
        text = data['text']
        mid = data['mid']
        screen_name = data['user']['screen_name']
        print('comment: ', [screen_name, mid, text])
        get_child_comment(mid)


# 爬取一页数据
def get_one_page(url):
    time.sleep(3)
    response = requests.get(url)

    # 只有字典才可以使用json接口数据请求
    data = response.json()
    cards = data['data']['cards']
    for card in cards:
        if card.get('mblog'):
            m_blog = card.get('mblog')
            text = m_blog.get('text')
            mid = m_blog.get('mid')
            screen_name = m_blog.get('user').get('screen_name')
            print([screen_name, mid, text])
            get_hot_comments(mid)


def main(): 
    for page in range(1, 2):
        url = 'https://m.weibo.cn/api/container/getIndex?containerid=2304131866882821_-_WEIBO_SECOND_PROFILE_WEIBO&luicode=10000011&lfid=2302831866882821&page_type=03&page=' + str(page)
        get_one_page(url)


if __name__ == "__main__":
    main()