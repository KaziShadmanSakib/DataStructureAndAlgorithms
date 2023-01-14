# Name- Kazi Shadman Sakib */
# Roll- 97 */
import random

# set of keys
keys = random.sample(range(1, 100000), 10000)
print(len(keys))
i = 0
file = open("setOfKeys.txt", 'w')
for key in keys:
	if i == len(keys)-1:
		file.write(str(key))
	else:
		file.write(str(key) + '\n')
	i = i + 1
file.close()

# insertion sequence for these 10000 numbers.
insertSeq = random.sample(range(1, 10001), 10000)
print(len(insertSeq))
i = 0
file = open("insertionSequence.txt", 'w')
for seq in insertSeq:
	if i == len(insertSeq)-1:
		file.write(str(seq))
	else:
		file.write(str(seq) + '\n')
	i = i + 1
file.close()

# search sequence of 3000 numbers
# 0.3 probability of not being in the key set
# 0.7 probability of belonging to the key set
notInSetOfKeys = random.sample(range(100001, 999999), 900)
temp = keys.copy()
del temp[2100:10000]
searchSeq = temp + notInSetOfKeys
random.shuffle(searchSeq)
print(len(temp))
print(len(notInSetOfKeys))
print(len(searchSeq))
i = 0
file = open("searchSequence.txt", 'w')
for seq in searchSeq:
	if i == len(searchSeq)-1:
		file.write(str(seq))
	else:
		file.write(str(seq) + '\n')
	i = i + 1
file.close()

# insert-search sequence
# with 0.7 probability of the insert operation
# and 0.3 probability of the search operation
# where 1 means insert and 0 means search
insertSearchSeq = [0] * 3000 + [1] * 7000
random.shuffle(insertSearchSeq)
print(len(insertSearchSeq))
i = 0
file = open("insertSearchSequence.txt", 'w')
for seq in insertSearchSeq:
	if i == len(insertSearchSeq)-1:
		file.write(str(seq))
	else:
		file.write(str(seq) + '\n')
	i = i + 1
file.close()