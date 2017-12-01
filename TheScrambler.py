# Try to remember
import random
temp1 = []
sentence = raw_input("Enter the sentence you want scrambled: ");
print ("The old sentence is :"), sentence
for i in range(0, len(sentence)):
    temp1.append(sentence[i])
temp2 = []
length = len(sentence)
word = []
numwords = 1
x = 0
newword = ''
while x <= (length-1):
    word.append(temp1[x])

    if word[x] ==' ':
        temp2.append(newword)
        newword = ''
        numwords += 1
    if word[x] <> ' ':
        newword = newword + word[x]
    x= x + 1
temp2.append(newword)


num = numwords
Scrambled = []
while numwords >0:
    n = int(numwords*random.random())
    Scrambled.append(temp2[n])
    temp2.pop(n)
    numwords -=1

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
