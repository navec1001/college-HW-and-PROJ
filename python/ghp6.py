dataset = []
numin = int(input("Enter how many numbers you'd like to enter (as a whole number): "))


if numin > 30 or numin < 0:
    print("Invalid number! Reload the program and try again!")
    exit()

for i in range(numin):
    newnum = int(input("Enter a whole number into the dataset: "))
    dataset.append(newnum)

print("Your dataset is:")
for x in dataset: print (str(x) + " ", end='')
print("")

print("Number of entries: " + str(len(dataset)))
print("Minimum value: " + str(min(dataset)))
print("Maximum value: " + str(max(dataset)))
datarange = int(max(dataset)) - int(min(dataset))
print("The range: " + str(datarange))
from statistics import mean
datamean = mean(dataset)
print("The mean: " + str(datamean))
from statistics import variance
datavar = variance(dataset)
print("The variance: " + str(datavar))
from math import sqrt
datastddev = sqrt(datavar)
print("The standard deviation: " + str(datastddev))