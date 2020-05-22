while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except:
        pass

i = 1

while i <= height:
    print(" " * (height - i), end = "")
    print("#" * i, end = "  ")
    print("#" * i)
    i+=1
