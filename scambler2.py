# Try to remember
import random
temp1 = []
sentence = 'the games people play'
print ("The old sentence is"), sentence
for i in range(0, len(sentence)):
    temp1.append(sentence[i])
print temp1
temp2 = []
length = len(sentence)
print ("length"), length
word = []
numwords = 1
x = 0
newword = ''
while x <= (length-1):
    word.append(temp1[x])
    print ("word"), word
    if word[x] ==' ':
        temp2.append(newword)
        newword = ''
        numwords += 1
    if word[x] <> ' ':
        newword = newword + word[x]
    print numwords
    print ("newword"), newword
    print("temp2"),temp2
    x= x + 1
temp2.append(newword)
print word
print('here3')
print ("the last newword"), newword
print("last temp2"), temp2
print ("number of words"), numwords
num = numwords
Scrambled = []
while numwords >0:
    n = int(numwords*random.random())
    Scrambled.append(temp2[n])
    temp2.pop(n)
    numwords -=1
print("Scrambled is"), Scrambled
NewSentence = ''
for i in range(0, num):
    NewSentence = NewSentence + Scrambled[i]
    NewSentence = NewSentence + ' '

print ("Your scrambled sentence is:"), NewSentence


#print (length)
#while length >= 0:
    #x = int(length*random.random())
    #scrambled_list.append(temp1[x])
    #temp1.pop(x)
    #length -= 1
#new_word = ''
#for i in range (0, len(word)):
    #new_word = new_word + scrambled_list[i]

#print ("Scrambled word is"), new_word
