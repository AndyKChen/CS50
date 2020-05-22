import sys
import csv


def main():

    # ensure correct usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(0)

    # open dna sequence file to read into a string
    f = open(sys.argv[2],"r")
    s = f.read()

    # initialize total counts of consecutive STR
    count_AGATC = 0
    count_AATG = 0
    count_TATC = 0

    # bool flag to determine when a count is complete
    flag_AGATC = False
    flag_AATG = False
    flag_TATC = False

    for i in range(len(s)):
        substr = s[i: i + 4]

        # check for AGATC STR
        if check(substr) == "AGAT" and s[i + 4] == "C" and flag_AGATC == False:
            substr = s[i + 5: i + 9]

            # check if repeating
            if check(substr) == "AGAT" and s[i + 9] == "C":
                j = i
                k = i + 4

                # if repeating, start counting number of repeating STRs, until check(substr) yield different result
                while True:
                    substr = s[j:k]

                    if check(substr) == "AGAT" and s[j + 4] == "C":
                        count_AGATC += 1

                    else:
                        flag_AGATC = True
                        break

                    j += 5
                    k += 5

        elif check(substr) == "AATG" and flag_AATG == False:
            substr = s[i + 4: i + 8]

            if check(substr) == "AATG":
                j = i
                k = i + 4

                while True:
                    substr = s[j:k]

                    if check(substr) == "AATG":
                        count_AATG += 1

                    else:
                        flag_AATG = True
                        break

                    j += 4
                    k += 4

        elif check(substr) == "TATC" and flag_TATC == False:
            substr = s[i + 4: i + 8]

            if check(substr) == "TATC":
                j = i
                k = i + 4

                while True:
                    substr = s[j:k]

                    if check(substr) == "TATC":
                        count_TATC += 1

                    else:
                        flag_TATC = True
                        break

                    j += 4
                    k += 4

    # if any STRs have not repeated, set value to the minimum of once
    if flag_AGATC == False:
        count_AGATC = 1

    if flag_AATG == False:
        count_AATG = 1

    if flag_TATC == False:
        count_TATC = 1

    # open CSV file and read each row into a dictionary
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)

        # get total count for each STR in each row
        for row in reader:
            AGATC = int(row["AGATC"])
            AATG = int(row["AATG"])
            TATC = int(row["TATC"])

            # print name if count of each STR matches
            if AGATC == count_AGATC and AATG == count_AATG and TATC == count_TATC:
                print(row["name"])
                exit(1)

    print("No Match")


# check function to check for beggining of a STR
def check(substr):
    if substr == "AGAT":
        return "AGAT"
    if substr == "AATG":
        return "AATG"
    if substr == "TATC":
        return "TATC"


# call main function
main()
