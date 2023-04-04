 #  -*-coding:utf8 -*-

import urllib.request
import urllib.parse
import json
import time

'''
header = {}
header['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29'
'''

while True:
    content = input('please enter the content to translate:')
    if content == 'q!':
        break

    url = 'https://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'

    data = {}
    data['i'] = content
    data['from'] = 'AUTO'
    data['to'] = 'AUTO'
    data['smartresult'] = 'dict'
    data['client'] = 'fanyideskweb'
    data['salt'] = '16509646118931'
    data['sign'] = '7bafa7c989ffa8af75752591a0d9b50e'
    data['lts'] = '1650964611893'
    data['bv'] = 'cfddf5227f0e08de65d069a5a4aeacca'
    data['doctype'] = 'json'
    data['version'] = '2.1'
    data['keyfrom'] = 'fanyi.web'
    data['action'] = 'FY_BY_REALTlME'

    data = urllib.parse.urlencode(data).encode('utf-8')

    req = urllib.request.Request(url, data)
    req.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29')

    response = urllib.request.urlopen(req)
    html = response.read().decode('utf-8')

    target = json.loads(html)
    target = target['translateResult'][0][0]['tgt']

    print('the translation result is:%s' % target)

    time.sleep(5)
