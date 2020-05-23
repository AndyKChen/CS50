import sys
from cs50 import SQL

def main():
    if len(sys.argv) != 2:
        print("python roster.py houseName")
        exit(0)

    # establish connection with database
    db = SQL("sqlite:///students.db")

    # print each row of query
    for row in db.execute('Select DISTINCT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first', sys.argv[1]):
        try:
            print(row['first'] + ' ' + row['middle'] + ' ' + row['last'] + ', born ' + str(row['birth']))
        except:
            print(row['first'] + ' ' + row['last'] + ', ' + 'born ' + str(row['birth']))


main()
