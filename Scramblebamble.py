#Scramble a new word
import random
new_word_scr =[]
word = "ROTAVATOR"
print("Old word :",word )
for i in range(0, len(word)):
    new_word_scr.append(word[i])


scrambled_list= []
l= len(word)-1
while l >=0:
    x= int(l*random.random())
    scrambled_list.append(new_word_scr[x])
    new_word_scr.pop(x)

    l=l-1

new_word =' '
for i in range(0,len(word)):
    new_word = new_word+scrambled_list[i]
print("New Scrambled word : ", new_word)