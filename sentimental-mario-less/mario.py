# TODO
while (True):
    Height = int(input("Height: "))

for i in range(1,Height+1):
    print(" " * (Height - i), end = "")
    print("#" * i, end = "")
    print()

