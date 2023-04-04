import json

import requests
from bs4 import BeautifulSoup
import random
import time
def get_User_Agent():
    User_Agent = [
        'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
        'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1',
        'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:6.0) Gecko/20100101 Firefox/6.0',
        'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50',
        'Opera/9.80 (Windows NT 6.1; U; zh-cn) Presto/2.9.168 Version/11.50',
        'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.2125.122 UBrowser/4.0.3214.0 Safari/537.36',
        'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Maxthon/4.4.3.4000 Chrome/30.0.1599.101 Safari/537.36',
        'Mozilla/5.0 (Windows NT 5.1) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.84 Safari/535.11 SE 2.X MetaSr 1.0',
        'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 732; .NET4.0C; .NET4.0E)'
    ]
    len_user_agent = len(User_Agent)
    random_num = random.randint(0, len_user_agent - 1)
    user_agent = User_Agent[random_num]
    return user_agent

def get_text(tag):
    if tag.find('span', attrs={'class': 'content-him content-text content-him-patient'}):
        return "Q: " + tag.find('span', attrs={'class': 'content-him content-text content-him-patient'}).text.strip() + "  Time:" + tag.find('div', attrs={'class': 'msg-time'}).text.strip().replace('\n', ' ').replace('\r', ' ')

    elif tag.find('span', attrs={'class': 'content-com-text'}):
        word = []
        for i in tag.find_all('span', attrs={'class': 'content-com-text'}):
            word.append("A:" + i.text.strip().replace('\n', ' ').replace('\r', ' ') + "  Time:" + tag.find('div', attrs={'class': 'msg-time'}).text.strip().replace('\n', ' ').replace('\r', ' '))
        return word

    elif tag.find('span', attrs={'class': 'content-him content-text'}):
        return "A: " + tag.find('span', attrs={'class': 'content-him content-text'}).text.strip().replace('\n', ' ').replace('\r', ' ') + "  Time:" + tag.find('div', attrs={'class': 'msg-time'}).text.strip().replace('\n', ' ').replace('\r', ' ')

    elif tag.find('span', attrs={'class': 'content-audio-text'}):
        return "A: " + tag.find('span', attrs={'class': 'content-audio-text'}).text.strip().replace('\n', ' ').replace('\r', ' ') + "  Time:" + tag.find('div', attrs={'class': 'msg-time'}).text.strip().replace('\n', ' ').replace('\r', ' ')

    else:
        return None

def craw_task_url(url):
    response = requests.get(
        url=url,
        headers={
            'User-Agent': get_User_Agent()
        }
    )
    bs = BeautifulSoup(response.text, 'lxml')
    text = []
    right = bs.find('div', attrs={'class': 'msg-item item-right'})
    left = bs.find('div', attrs={'class': 'msg-item item-left'})
    try:
        if right == None:
            context_first = left
            context_siblings = left.find_next_siblings()
            text.append(get_text(context_first))
            for i in range(len(left.find_next_siblings())):
                text.append(get_text(context_siblings[i]))

        elif left == None:
            context_first = right
            context_siblings = right.find_next_siblings()
            text.append(get_text(context_first))
            for i in range(len(right.find_next_siblings())):
                text.append(get_text(context_siblings[i]))

        elif len(right.find_next_siblings()) > len(left.find_next_siblings()):
            context_first = right
            context_siblings = right.find_next_siblings()
            text.append(get_text(context_first))
            for i in range(len(right.find_next_siblings())):
                text.append(get_text(context_siblings[i]))

        elif len(right.find_next_siblings()) < len(left.find_next_siblings()):
            context_first = left
            context_siblings = left.find_next_siblings()
            text.append(get_text(context_first))
            for i in range(len(left.find_next_siblings())):
                text.append(get_text(context_siblings[i]))
    except:
        print("error")
    return text

def craw_doctor_url(url):
    response = requests.get(
        url=url,
        headers={
            'User-Agent': get_User_Agent()
        }
    )
    global affiliate,department
    bs = BeautifulSoup(response.text, 'lxml')
    doc_name = bs.find('h1', attrs={'class': 'doctor-name js-doctor-name'}).text
    doc_title = bs.find('span', attrs={'class': 'doctor-title'}).text
    affAnddept = bs.find('li', attrs={'class': 'doctor-faculty'}).find_all('a')
    temp = 0
    for i in affAnddept:
        for j in i:
            if temp % 2 == 0:
                affiliate = j.text
            else:
                department =j.text
            temp += 1
    return doc_name,doc_title,affiliate,department

def save_txt(data):
    with open('data.json', 'a', encoding='utf-8') as fp:
        json.dump(data, fp, ensure_ascii=False, indent=4)

def sava_context(data):
    with open('context.json', 'a', encoding='utf-8') as fp:
        json.dump(data, fp, ensure_ascii=False, indent=4)

if __name__ == '__main__':
    requests.packages.urllib3.disable_warnings()
    response = requests.get(
        url='https://www.haodf.com/bingcheng/list.html?p=1',
        headers={
            'User-Agent': get_User_Agent()
        },
        verify = False
    )
    result = {}
    bs = BeautifulSoup(response.text, 'lxml')
    tag_a = bs.find_all('a', attrs={'class': 'fl'})
    temp = 0
    for i in tag_a:
        temp += 1
        if temp % 2 == 1:
            task_url = i.get('href')
            context = craw_task_url(task_url)
            task_title = i.get('title')
            result['task_title'] = task_title
            result['context'] = context
        elif temp % 2 == 0:
            doc_url = i.get('href')
            result['doc_name'], result['doc_title'], result['affiliate'], result['department'] = craw_doctor_url(doc_url)
            result['doc_url'] = doc_url
            temp = 0
            # save_txt(result)
            sava_context(context)
        # time.sleep(1)
