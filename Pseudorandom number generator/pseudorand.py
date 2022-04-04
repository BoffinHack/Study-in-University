import math

#Start number
a = float(0.159845022)
print("Start number ", a)

#Big integer 
g = int(3623459)
print("Big integer ", g)

#Tochnost 
k = int(2)
print("Tochnost ", k)

#Кол-во чисел
c = int(15000)
print("Кол-во чисел ", c)

print("")

list = []

#f = open('C:/random.txt','w+')
#wstr = ""
#s1 = " "
#s2 = "\n"

#Random process
for i in range (c):
    list.append(a)
    #print(i + 1, ")", list[i])
    #wstr = s1 + str(list[i]) + s2
    #f.write(wstr)
    a = int(((g * a) % 1) * pow(10, k)) / pow(10, k)
    a = round(a, k)

#f.close()

L = int(0)
P = int(0)

i = int(0)
j = int(0)

uwu = int(0)
tmp = float(0)

while(i < len(list)):
    tmp = list[i]
    while(j < len(list)):
        if(i != j):
            if(tmp == list[j]):
                L = j
                P = j - i
                uwu = 1
                break
        j += 1
    j = 0
    if(uwu == 1):
        break
    i += 1

print("P =", "", P)

print("L =", "", L)

if(L == 0):
    print("", "Малый объем выборки")

#Interval
r = int(1 + 3.3 * math.log10(c))
print("r - ", "", r)

#Svoboda
s = int(r - 1)
print("s - ", "", s)

#Probability PI
p = float(1 / r)
print("p - ", "", p)

#Xi^2
xi = float(0.0)
shag = float(1 / r)
count = int(0)
i = 0
j = 0
while(i < r):
    while(j < c):
        if((shag * i) <= list[j] <= (shag * (i + 1))):
            count += 1
        j += 1
    j = 0
    print(count, "")
    xi += pow((count - c * p), 2) / (c * p)
    count = 0
    if(shag * (i + 1) > 1):
        break
    i += 1

print("xi - ", "", xi)
