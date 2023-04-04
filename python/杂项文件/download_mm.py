import urllib.request
import os

def get_page(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent', 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Mobile Safari/537.36')
    response = urllib.request.urlopen(url)
    html = response.read().decode('utf-8')

    a = html.find('inPageShowHidden')

def find_imgs(page_url):

def save_imgs(folder, img_addrs):
    

def down_load_mm(folder = 'OOXX', pages = 10):
    os.mkdir(folder)
    os.chdir(folder)

    url = 'https://www.vcg.com/creative-image/meinv/'

    page_num = int(get_page(url))

    for i in range(pages):
        page_num -= i
        page_url = 'https://www.vcg.com/creative/' + str(page_num)
        img_addrs = find_imgs(page_url)
        save_imgs(folder, img_addrs)

if __name__ == 'main':
    down_load_mm()