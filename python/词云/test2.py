# coding=gbk

import jieba
import nltk
from wordcloud import WordCloud,ImageColorGenerator
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']

def get_txt():
    files = open('data.csv').read()
    return files

def get_stopwords():
    files = open('stopword.txt').read()
    return files

def jiebafenci(data,stopwords):
    word = jieba.cut(data,cut_all = False)
    final = ''
    for seg in word:
        if seg not in stopwords:
            final += seg
    final = jieba.cut(final,cut_all = False)
    word_freq = nltk.FreqDist(final)
    puts_1 = open('worddist.txt','w')
    puts_1.writelines('以下是词频结果'+'\n')
    for key, val in sorted(word_freq.items(), key = lambda x: (x[1], x[0]), reverse = True):
        work = (str(key) + ':' + str(val))
        puts_1.write(work + '\n')
    puts_1.close()
    print("统计词频及写入文件结束")

def ciyun(data):
    stopwords = get_stopwords()
    word = jieba.cut(data, cut_all=False)
    final = ''
    for seg in word:
        if seg not in stopwords:
            final += seg
    final = jieba.cut(final, cut_all=False)
    freq_word = (' '.join(final))
    figure_coloring = np.array(Image.open('ChinaMap.png'))
    wcd = WordCloud(
        font_path="C:\Windows\Fonts\STSONG.TTF",
        max_font_size=40,
        max_words=4000,
        mask=figure_coloring,
        background_color='white',
        margin = 2).generate(freq_word).to_file('词频云图.png')
    image_colors = ImageColorGenerator(figure_coloring)
    plt.imshow(wcd.recolor(color_func = image_colors),interpolation = "bilinear")
    plt.show



if __name__ == '__main__':
    data = get_txt()
    stopwords = get_stopwords()
    jiebafenci(data,stopwords)
    ciyun(data)
