import urllib.request
import random

# url = 'http://45.32.264.128/ip.php'
url = 'http://whatismyip.com.tw'

iplist = ['111.22.3.126:8085', '221.4.241.198:9091', '120.220.220.95:8085', '112.6.117.135:8085']

proxy_support = urllib.request.ProxyHandler({'http' : random.choice(iplist)})

opener = urllib.request.build_opener(proxy_support)
# opener.addheaders = [('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29')]

urllib.request.install_opener(opener)

response = urllib.request.urlopen(url)
html = response.read().decode('utf-8')

print(html)