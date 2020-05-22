import cs50 as cs

def main():
    n = cs.get_int("Number: ")

    l = [int(x) for x in str(n)]
    l.reverse()

    total1 = 0
    total2 = 0

    for i in range(0,len(l)):

        if i%2 == 0:
            total1+=l[i]

        else:
            j = l[i]*2

            if j > 9:
                total2+=(j - 9)

            else:
                total2+=j

    if (total1 + total2)%10 == 0:
        check(l)

    else:
        print("INVALID")

def check(l):
    l.reverse()
    length = len(l)

    if length == 15 and l[0] == 3 and (l[1] == 4 or l[1] == 7):
        print("AMEX")

    elif length == 16 and l[0] == 5 and (l[1] == 1 or l[1] == 2 or l[1] == 3 or l[1] == 4 or l[1] == 5):
        print("MASTERCARD")

    elif l[0] == 4 and (length == 13 or length == 16):
        print("VISA")

    else:
        print("INVALID")

main()
