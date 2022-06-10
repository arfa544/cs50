# TODO
while (True):
    Height = int(input("Height: "))
    if (Height > 1 or Height < 8):
        break

for i in range(1,Height+1):
    print(" " * (Height - i), end = "")
    print("#" * i, end = "")
    print()

