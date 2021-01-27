# -*- coding: utf-8 -*-
from flask import Flask,request
from pickle import load
from jieba  import cut
from sklearn.feature_extraction.text import TfidfVectorizer
app = Flask(__name__)

if 'clfpa' not in dir():
    # 加载模型
    with open('../model/clfpa.model',mode='rb') as f:
        clfpa = load(f) 
if 'a_list' not in dir():
    # 加载词汇列表
    with open('../data/blogswordslist.pickle',mode='rb') as f2:
         vocabulary = list(load(f2))
    print("加载模型与词汇表成功")
    
@app.route('/',methods=['POST'])
def docclassify():
    docu = request.get_json()
    stop_words = list(['\n','','。','，','|','【','】',':',' ','...','/','.','_','+','=','[',']','-'])
    aa = []
    aa.append(' '.join([ x for x in " ".join(cut(str(docu))).split(' ') if x not in stop_words]))
    # tfidf向量
    vectorizer = TfidfVectorizer(stop_words=stop_words,vocabulary=vocabulary)
    return ' '.join(str(int(clfpa.predict(vectorizer.fit_transform(aa)))))

if __name__ == "__main__":
    app.run()
    