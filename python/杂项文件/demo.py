import urllib.request

response = urllib.request.urlopen('https://placekitten.com/800/700')
cat_img = response.read()

with open('cat_800_700.jpg', 'wb') as f:
    f.write(cat_img)