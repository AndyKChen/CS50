import sys
import csv
from cs50 import SQL

def main():
    # ensure correct usage
    if len(sys.argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(0)

    # establish connection with database
    db = SQL("sqlite:///students.db")

    # open csv file and create a reader to read each line of csv file
    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)

        for row in reader:
            name = row["name"].split()
            house = row["house"]
            birth = row["birth"]

            # determines first, middle, last name depending on length of name list
            if len(name) == 3:
                first = name[0]
                middle = name[1]
                last = name[2]

            else:
                first = name[0]
                middle = None
                last = name[1]

            # insert values into database
            db.execute("INSERT INTO students ('first', 'middle', 'last', 'house', 'birth') VALUES (?, ?, ?, ?, ?)",
                   first, middle, last, house, birth)

main()
