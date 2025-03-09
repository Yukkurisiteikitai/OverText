import random

words = [chr(ord("a")+i) for i in range(26)]
print(words)

temp_do = ""

def fe(c:int):
    global temp_do
    for i in range(c):
        temp_do += words[random.randint(0,25)] 
fe(2 * 1000000)
print()

with open("tekitou.txt","a",encoding="utf-8")as f:
    f.write(temp_do)